/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_thread.h
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

#ifndef _JX_THREAD_H_
#define _JX_THREAD_H_

#include <osal/jx_stdint.h>

#define JX_THREAD_STACK_SIZE       1024                             /**thread stack default size*/
#define JX_HIGH_PRIOLEVEL          5                                /**thread high priolevel,default prio is 5*/
#define JX_MIDDLE_PRIOLEVEL        15                               /**thread middle priolevel,default prio is 15*/
#define JX_LOW_PRIOLEVEL           25                               /**thread low priolevel,default prio is 25*/
#define JX_THREAD_MAX_COUNT        256                             /**thread max count*/

#define JX_THREAD_CTRL_STARTUP                  0           /**thread startup cmd*/
#define JX_THREAD_CTRL_CLOSE                    1           /**thread close cmd*/
#define JX_THREAD_CTRL_CHANGE_PRIORITY          2           /**thread change prio cmd*/
#define JX_THREAD_CTRL_BIND_CPU                 4           /**thread bind cpu cmd*/

typedef void *jx_threadhandle_t;

/**@struct jx_thread_para
* @brief thread creation para structure
*/
struct jx_thread_para {
    jx_char_t *name;                              /**thread name,at most 8 char*/
    jx_void_t (*entry)(jx_void_t *parameter);     /**thread entry*/
    jx_void_t *parameter;                         /**thread entry parameter*/
    jx_u32_t stack_size;                          /**stack size*/
    jx_u32_t tick;                                /**time slice*/
    jx_u8_t priolevel;                            /**thread prio level*/
    jx_u8_t prio;                                 /**thread prio*/
};
typedef struct jx_thread_para       jx_thread_para_t;
typedef struct jx_thread_para      *jx_pthread_para_t;

/**
 * @brief create a thread dynamicly
 * @param[in] pthread_para thread creation para structure pointer
 * @retval thread handle
 */
jx_threadhandle_t jx_thread_create(jx_pthread_para_t pthread_para);

/**
 * @brief start up a thread
 * @param[in] handle thread handle
 * @retval operation status
 */
jx_err_t jx_thread_startup(jx_threadhandle_t handle);

/**
 * @brief let current thread sleep for some ticks
 * @param[in] tick thread sleep time
 * @retval operation status
 */
jx_err_t jx_thread_sleep(jx_u32_t tick);

/**
* @brief let current thread sleep some ms
* @param[in] ms value to sleep
* @retval operation status
*/
jx_err_t jx_thread_sleep_ms(jx_s32_t ms);

/**
 * @brief get a thread prio
 * @param[out] prio thread prio
 * @retval operation status
 */
jx_err_t jx_thread_prio_get(jx_u8_t *prio);

/**
 * @brief get a thread id
 * @param[out] id thread id
 * @retval operation status
 */
jx_err_t jx_thread_id_get(jx_u8_t *id);

/**
 * @brief get a thread name
 * @param[out] name thread name
 * @retval operation status
 */
jx_err_t jx_thread_name_get(jx_char_t *name);

/**
 * @brief get self thread handle
 * @retval thread handle
 */
jx_threadhandle_t jx_thread_self(jx_void_t);

/**
 * @brief perform one scheduling
 */
jx_void_t jx_schedule(jx_void_t);

/**
 * @brief lock the thread scheduler.
 */
jx_void_t jx_thread_lock(jx_void_t);

/**
 * @brief unlock the thread scheduler.
 */
jx_void_t jx_thread_unlock(jx_void_t);

/**
 * @brief control thread behaviors according to control command.
 * @param[in] handle thread handle
 * @param[in] cmd control command
 * @param[in] arg control command arg
 * @retval operation status
 */
jx_err_t jx_thread_control(jx_threadhandle_t handle, jx_s32_t cmd, jx_void_t *arg);

/**
 * @brief delete a thread
 * @param[in] ptaskinfo thread creation info structure pointer
 * @retval operation status
 */
jx_err_t jx_thread_delete(jx_threadhandle_t handle);

/**
 * @brief get cpu id
 * @retval cpu id
 */
jx_s32_t jx_cpu_id_get(jx_void_t);

#endif
