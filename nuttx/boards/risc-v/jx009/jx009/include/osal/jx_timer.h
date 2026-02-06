/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_timer.h
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

#ifndef _JX_TIMER_H_
#define _JX_TIMER_H_

#include <osal/jx_stdint.h>

#define   JX_TIMER_FLAG_ONE_SHOT        0            /**one timing,used together with hardware timing or softwware timing*/
#define   JX_TIMER_FLAG_PERIODIC        4            /**period timing,used together with hardware timing or softwware timing*/
#define   JX_TIMER_FLAG_HARD_TIMER      0            /**hardware timing,used together with one timing or period timing*/
#define   JX_TIMER_FLAG_SOFT_TIMER      8            /**softwware timing,used together with one timing or period timing*/

#define  JX_TIMER_CTRL_SET_TIME          0             /**set timer control command*/
#define  JX_TIMER_CTRL_GET_TIME          1             /**get timer control command*/
#define  JX_TIMER_CTRL_SET_ONESHOT       2             /**change timer to one shot*/
#define  JX_TIMER_CTRL_SET_PERIODIC      3             /**change timer to periodic*/
#define  JX_TIMER_CTRL_GET_STATE         4             /**get timer run state active or deactive*/
#define  JX_TIMER_CTRL_GET_REMAIN_TIME   5             /**get the remaining time*/

typedef void *jx_timerhandle_t;

/**@struct jx_timer_para
* @brief timer creation para structure
*/
struct jx_timer_para {
    jx_char_t *name;                              /**timer name,at most 8 char*/
    jx_void_t (*timeout)(jx_void_t *parameter);   /**timer callback*/
    jx_void_t *parameter;                         /**callback parameter parameter*/
    jx_u32_t time;                                /**timed time*/
    jx_u8_t flag;                                 /**timer time type*/
};
typedef struct jx_timer_para    jx_timer_para_t;
typedef struct jx_timer_para   *jx_ptimer_para_t;

/**
* @brief create a timer dynamicly
* @param[in] ptimer_para pointer of timer creation para structure
* @retval timer handle
*/
jx_timerhandle_t jx_timer_create(jx_ptimer_para_t ptimer_para);

/**
* @brief start a timer
* @param[in] handle pointer of a timer
* @retval operation status
*/
jx_err_t jx_timer_start(jx_timerhandle_t handle);

/**
* @brief control timer option
* @param[in] handle pointer of a timer
* @param[in] cmd timer control command
* @param[in] arg command argument
* @retval operation status
*/
jx_err_t jx_timer_contrl(jx_timerhandle_t handle, jx_s32_t cmd, jx_void_t *arg);

/**
* @brief stop a timer
* @param[in] handle pointer of a timer
* @retval operation status
*/
jx_err_t jx_timer_stop(jx_timerhandle_t handle);

/**
* @brief delete a timer
* @param[in] ptimerinfo pointer of timer creation info structure
* @retval operation status
*/
jx_err_t jx_timer_delete(jx_timerhandle_t handle);

/**
* @brief get current tick.
* @retval current tick
*/
jx_u32_t jx_tick_get(jx_void_t);

/**
* @brief set tick
* @param[in] tick value to set
*/
jx_void_t jx_tick_set(jx_u32_t tick);

/**
 * @brief calculate the tick from millisecond.
 * @param[in] ms specified millisecond.
 * @retval calculated tick.
 */
jx_u32_t jx_tick_from_ms(jx_s32_t ms);

/**
 * @brief return the passed millisecond from boot
 * @retval return passed millisecond from boot
 */
jx_u32_t jx_tick_get_ms(jx_void_t);

#endif
