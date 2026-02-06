/****************************************************************************
 * boards/risc-v/jx009/jx009/src/osal/jx_irq.c
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

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <arch/board/osal/jx_irq.h>
#include <assert.h>


jx_void_t jx_irq_install(jx_u32_t irq_num, jx_irq_para_t *irq_para)
{
    assert(irq_para != JX_NULL);
    irq_attach(irq_num, irq_para->handler, irq_para->para);
}

jx_void_t jx_irq_enable(jx_u32_t irq_num)
{
    up_enable_irq(irq_num);
    return;
}

jx_void_t jx_irq_disable(jx_u32_t irq_num)
{
    up_disable_irq(irq_num);
    return;
}

jx_void_t jx_irq_pending_clear(jx_u32_t irq_num)
{
}
