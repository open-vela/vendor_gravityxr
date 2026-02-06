/****************************************************************************
 * boards/risc-v/jx009/jx009/src/osal/jx_thread.c
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

#include <osal/jx_thread.h>
#include <osal/jx_err.h>
#include <osal/jx_interrupt.h>

#include <nuttx/config.h>
#include <nuttx/sched.h>
//#include <pthread.h>
#include <unistd.h>

#define JX_THREAD_MAX_PRIO      RT_THREAD_PRIORITY_MAX           /**thread max prio(32)*/
typedef struct rt_thread        jx_thread_t;                     /**Thread abstraction layer definition*/

#if defined(JX_THREADID_MAP)
/**@struct jx_threadid_map
* @brief thread address mapping thread id
*/
struct jx_threadid_map {
    jx_handle_t pthread;        /**thread handle*/
    jx_u8_t id;                 /**thread id*/
};
typedef struct jx_threadid_map jx_threadid_map_t;

static jx_u32_t s_thread_index = 0;
static jx_u8_t s_thread_id = 0;
static jx_threadid_map_t s_threadid_map[JX_THREAD_MAX_COUNT];
#endif


jx_threadhandle_t jx_thread_create(jx_pthread_para_t pthread_para)
{
    jx_threadhandle_t handle;
    jx_u32_t level;

    RT_ASSERT(pthread_para != JX_NULL);
    RT_ASSERT(pthread_para->entry != JX_NULL);
    RT_ASSERT(pthread_para->priolevel <= JX_THREAD_MAX_PRIO);
    RT_ASSERT(pthread_para->prio <= JX_THREAD_MAX_PRIO);

    if (pthread_para->name == JX_NULL) {
        pthread_para->name = (jx_char_t *)"thread";
    }
    if (pthread_para->prio != 0) {
        pthread_para->prio--;
    } else {
        if (pthread_para->priolevel != 0) {
            pthread_para->prio = pthread_para->priolevel - 1;
        } else {
            pthread_para->prio = JX_THREAD_MAX_PRIO - 1;
        }
    }

    if (pthread_para->stack_size == 0) {
        pthread_para->stack_size = JX_THREAD_STACK_SIZE;
    }

    handle = rt_thread_create((const char *)pthread_para->name, pthread_para->entry,
                              pthread_para->parameter,
                              pthread_para->stack_size, pthread_para->prio, pthread_para->tick);

    if (handle != JX_NULL) {
        RT_ASSERT(s_thread_index < JX_THREAD_MAX_COUNT);
        level = jx_interrupt_lock();
    
#if defined(JX_THREADID_MAP)
        s_threadid_map[s_thread_index].pthread = handle;
        s_thread_id++;
        s_threadid_map[s_thread_index].id = s_thread_id;
        s_thread_index++;
#endif
        jx_interrupt_unlock(level);
    }
    return handle;
}

jx_err_t jx_thread_startup(jx_threadhandle_t handle)
{
    jx_s32_t err;

    RT_ASSERT(handle != JX_NULL);
    err = rt_thread_startup(handle);

    return -err;
}

jx_err_t jx_thread_sleep(jx_u32_t tick)
{
    jx_s32_t err;
    err = rt_thread_delay(tick);

    return -err;
}

jx_err_t jx_thread_sleep_ms(jx_s32_t ms)
{
    jx_s32_t err;

    err = rt_thread_mdelay(ms);

    return -err;
}

jx_err_t jx_thread_prio_get(jx_u8_t *prio)
{
    jx_thread_t *pthread;
    pthread = rt_thread_self();
    if (pthread == JX_NULL) {
        *prio = 0xff;
        return JX_INVAL;
    } else {
        *prio = RT_SCHED_PRIV(pthread).current_priority;
        return JX_OK;
    }
}

#if defined(JX_THREADID_MAP)
jx_err_t jx_thread_id_get(jx_u8_t *id)
{
    jx_u8_t i;
    jx_int_t result;
    jx_thread_t *pthread;
    pthread = rt_thread_self();
    if (pthread == JX_NULL) {
        *id = 0xff;
        return JX_INVAL;
    } else {
        result = rt_strcmp(pthread->parent.name, "main");
        if (0 == result) {
            *id = 0;
            return JX_OK;
        } else {
            result = rt_strcmp(pthread->parent.name, "tshell");
            if (0 == result) {
                *id = 0;
                return JX_OK;
            }
        }
        for (i = 0; i < s_thread_index; i++) {
            if (pthread == s_threadid_map[i].pthread) {
                *id = s_threadid_map[i].id;
                return JX_OK;
            }
        }
        *id = 0;
        return JX_ERROR;
    }
}
#endif

jx_err_t jx_thread_name_get(jx_char_t *name)
{
    jx_thread_t *pthread;

    pthread = rt_thread_self();
    if (pthread == JX_NULL) {
        return JX_INVAL;
    } else {
        (void) rt_strncpy(name, pthread->parent.name, 8);
        return JX_OK;
    }
}

jx_threadhandle_t jx_thread_self(jx_void_t)
{
    return rt_thread_self();
}

jx_void_t jx_schedule(jx_void_t)
{
    rt_schedule();
}


jx_void_t jx_thread_lock(jx_void_t)
{
    rt_enter_critical();
}

jx_void_t jx_thread_unlock(jx_void_t)
{
    rt_exit_critical();
}

jx_err_t jx_thread_control(jx_threadhandle_t handle, jx_s32_t cmd, jx_void_t *arg)
{
    jx_s32_t err;
    RT_ASSERT(handle != JX_NULL);

    if (JX_THREAD_CTRL_CHANGE_PRIORITY == cmd) {
        RT_ASSERT((*(jx_u8_t *)arg) <= JX_THREAD_MAX_PRIO);
        if ((*(jx_u8_t *)arg) == 0) {
            return JX_INVAL;
        }
        (*(jx_u8_t *)arg)--;
    }
    err = rt_thread_control(handle, cmd, arg);

    return -err;
}

jx_err_t jx_thread_delete(jx_threadhandle_t handle)
{
    jx_s32_t err;
    jx_s32_t level;
    jx_u8_t i;
    RT_ASSERT(handle != JX_NULL);

    err = rt_thread_delete(handle);

#if defined(JX_THREADID_MAP)
    level = jx_interrupt_lock();
    for (i = 0; i < s_thread_index; i++) {
        if (handle == s_threadid_map[i].pthread) {
            s_thread_index--;
            break;
        }
    }
    for (; i < s_thread_index; i++) {
        s_threadid_map[i].pthread = s_threadid_map[i + 1].pthread;
        s_threadid_map[i].id = s_threadid_map[i + 1].id;
    }
    jx_interrupt_unlock(level);
#endif

    return -err;
}

jx_s32_t jx_cpu_id_get(jx_void_t)
{
#ifdef JX_USING_SMP
    return rt_cpu_get_id();
#else
    return 0;
#endif
}
