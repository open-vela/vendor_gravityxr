/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_sem.h
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

#ifndef _JX_SEM_H_
#define _JX_SEM_H_

#include <osal/jx_stdint.h>

typedef void *jx_semhandle_t;

/**@struct jx_sem_para
* @brief sem creation para structure
*/
struct jx_sem_para {
    jx_char_t *name;                    /**sem name,at most 8 char*/
    jx_u32_t value;                     /**sem value*/
    jx_u8_t flag;                       /**multi-threaded semaphore acquisition mode, priority (1) or FIFO (0)*/
};
typedef struct jx_sem_para       jx_sem_para_t;
typedef struct jx_sem_para      *jx_psem_para_t;

/**
* @brief create a sem dynamicly
* @param[in] psem_para sem creation para structure pointer
* @retval sem handle
*/
jx_semhandle_t jx_sem_create(jx_psem_para_t psem_para);

/**
* @brief release a sem
* @param[in] handle sem pointer
* @retval operation status
*/
jx_err_t jx_sem_release(jx_semhandle_t handle);

/**
* @brief take a sem
* @param[in] handle sem pointer
* @param[in] timeout waiting for time
* @retval operation status
*/
jx_err_t jx_sem_take(jx_semhandle_t handle, jx_s32_t timeout);

/**
* @brief delete a sem
* @param[in] pseminfo sem creation info structure pointer
* @retval operation status
*/
jx_err_t jx_sem_delete(jx_semhandle_t handle);

#endif
