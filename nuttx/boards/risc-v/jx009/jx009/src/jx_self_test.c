/****************************************************************************
 * boards/risc-v/jx009/jx009/src/jx_self_test.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#include <pthread.h>
#include <sched.h>
#include <stdio.h>

#include <nuttx/config.h>
#include <arch/board/osal/jx_irq.h>
#include <nuttx/board.h>
#include <arch/chip/irq.h>

#include "jx_uart.h"
#include <arch/board/gxrlog.h>

#define IPC_A45_A45    (0x7c00b208)
#define IPC_N25F_A45   (0x7c00b200)

#define IPC_N25F_N25F  (0x7c00b204)
#define IPC_A45_N25F   (0x7c00b20c)

#define HW32_REG(ADDRESS)  (*((volatile unsigned long *)(ADDRESS)))

//typedef CODE int (*xcpt_t)(int irq, FAR void *context, FAR void *arg);
//typedef jx_int_t (*jx_isr_handler_t)(jx_int_t irq_num, jx_void_t *context, jx_void_t *param);
static jx_int_t ipc_irq_process(int irq_num, jx_void_t *regs, jx_void_t *args)
{
#if defined(CONFIG_SNPS_UART)
  nuttx_jx_console_output("JX009 ipc_irq_process\n");
#endif

#if defined(CONFIG_JX009_CORE_RAZOR)
  if(IRQ_IPC_A45_A45 == irq_num)
    HW32_REG(IPC_A45_A45) = 0;
#endif

#if defined(CONFIG_JX009_CORE_AON)
  if(IRQ_IPC_A45_N25F == irq_num)
    HW32_REG(IPC_A45_N25F) = 0;
  if(IRQ_IPC_N25F_N25F == irq_num)
    HW32_REG(IPC_N25F_N25F) = 0;
#endif
  return 0;
}

void jx_self_irq_test(void)
{
    jx_irq_para_t irq_para = {
      .prio = 1,
      .triger_mode = JX_IRQ_TRIGER_MODE_LEVEL,
      .para = NULL,
      .handler = ipc_irq_process,
  };
  // irq_attach(IRQ_IPC_A45_A45, ipc_irq_process, NULL);
  // up_enable_irq(IRQ_IPC_A45_A45);
#if defined(CONFIG_JX009_CORE_RAZOR)
  jx_irq_install(IRQ_IPC_A45_A45, &irq_para);
  jx_irq_enable(IRQ_IPC_A45_A45);
  HW32_REG(IPC_A45_A45) = 1;
#endif

#if defined(CONFIG_JX009_CORE_AON)
  jx_irq_install(IRQ_IPC_N25F_N25F, &irq_para);
  jx_irq_enable(IRQ_IPC_N25F_N25F);
  HW32_REG(IPC_N25F_N25F) = 1;
#endif
}

void *thread_entry(void *arg)
{
    int cnt = 0;
    pthread_t pself = pthread_self();
    int sleep_time = (int)pself;
    while(1)
    {
        sleep(sleep_time); //seconds
        GXRLOG_PR_INFO("JX", "Hello from pthread %d after sleep %d cnt %d\n",
          pself, sleep_time, cnt++);
    }
    return NULL;
}

#define JX_MUTLI_THREAD_CNT (2)
pthread_t thread[JX_MUTLI_THREAD_CNT];

static void jx009_multitask_test(void)
{
  pthread_attr_t attr;
  struct sched_param param;
  int ret, cnt = 0;
  char name[CONFIG_TASK_NAME_SIZE];

  while(cnt < JX_MUTLI_THREAD_CNT)
  {
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 0x1000);
    param.sched_priority = SCHED_PRIORITY_DEFAULT;
    pthread_attr_setschedparam(&attr, &param);

    ret = pthread_create(&thread[cnt], &attr, thread_entry, NULL);
    if (ret != 0)
      {
        GXRLOG_PR_ERR("JX", "Error: pthread_create failed: %d\n", ret);
        continue;
      }
    snprintf(name, CONFIG_TASK_NAME_SIZE, "jxth%d", cnt);
    pthread_setname_np(thread[cnt], name);
    GXRLOG_PR_ERR("JX", "pthread_create %s thread %ds, %p\n", name, thread[cnt], &thread[cnt]);
    cnt++;
  }
  return;
}

void jx_self_test(void)
{
    GXRLOG_PRINT(LOG_ERR, "%s starts, printed by gxrlog err level\n", __func__);
    GXRLOG_PR_EMERG("JX", "%s starts, printed by gxrlog emerg level\n", __func__);
    syslog(LOG_ERR, "%s starts, printed by syslog err level directly\n", __func__);
    jx_self_irq_test();
    jx009_multitask_test();
}
