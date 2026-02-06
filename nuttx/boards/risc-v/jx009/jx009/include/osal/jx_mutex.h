/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_mutex.h
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

#ifndef _JX_MUTEX_H_
#define _JX_MUTEX_H_

#include <osal/jx_stdint.h>

typedef void *jx_mutexhandle_t;

/**@struct jx_mutex_para
* @brief mutex creation para structure
*/
struct jx_mutex_para {
    jx_char_t *name;                  /**mutex name,at most 8 char*/
    jx_u8_t flag;                     /**multi-threaded mutex acquisition mode, priority (1) or FIFO (0)*/
};
typedef struct jx_mutex_para       jx_mutex_para_t;
typedef struct jx_mutex_para      *jx_pmutex_para_t;

/**
* @brief create a mutex dynamicly
* @param[in] pmutex_para mutex creation para structure pointer
* @retval mutex handle
*/
jx_mutexhandle_t jx_mutex_create(jx_pmutex_para_t pmutex_para);

/**
* @brief release mutex
* @param[in] handle mutex pointer
* @retval operation status
*/
jx_err_t jx_mutex_unlock(jx_mutexhandle_t handle);

/**
* @brief take mutex
* @param[in] handle mutex pointer
* @param[in] timeout waiting for time
* @retval operation status
*/
jx_err_t jx_mutex_lock(jx_mutexhandle_t handle, jx_s32_t timeout);

/**
* @brief delete mutex
* @param[in] pmutexinfo mutex creation info structure pointer
* @retval operation status
*/
jx_err_t jx_mutex_delete(jx_mutexhandle_t handle);

#endif
