/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_event.h
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

#ifndef _JX_EVENT_H_
#define _JX_EVENT_H_

#include <osal/jx_stdint.h>

#define   JX_EVENT_FLAG_AND             1                   /**event and operate*/
#define   JX_EVENT_FLAG_OR              2                   /**event or  operate*/
#define   JX_EVENT_FLAG_CLEAR           4                   /**event clear operate*/

#define   JX_WAITING_FOREVER            -1                  /**< Block forever until get resource. */
#define   JX_WAITING_NO                 0                   /**< Non-block. */

typedef void *jx_eventhandle_t;

/**@struct jx_event_para
* @brief event creation para structure
*/
struct jx_event_para {
    jx_char_t *name;                /**event name,at most 8 char*/
    jx_u8_t flag;                   /**multi-threaded event acquisition mode, priority (1) or FIFO (0)*/
};
typedef struct jx_event_para     jx_event_para_t;
typedef struct jx_event_para    *jx_pevent_para_t;

/**
* @brief create event set dynamicly
* @param[in] pevent_para mutex creation para structure pointer
* @retval event handle
*/
jx_eventhandle_t jx_event_create(jx_pevent_para_t pevent_para);

/**
* @brief send a event
* @param[in] handle event set pointer
* @param[in] set event send bit
* @retval operation status
*/
jx_err_t jx_event_send(jx_eventhandle_t handle, jx_u32_t set);

/**
* @brief recv a or some events
* @param[in] handle event set pointer
* @param[in] set event recv bit
* @param[in] option event action
* @param[in] timeout waiting for time
* @retval event bit
*/
jx_u32_t jx_event_recv(jx_eventhandle_t handle, jx_u32_t set, jx_u8_t option, jx_s32_t timeout);

/**
* @brief delete event set
* @param[in] peventinfo event creation info structure pointer
* @retval operation status
*/
jx_err_t jx_event_delete(jx_eventhandle_t handle);

#endif
