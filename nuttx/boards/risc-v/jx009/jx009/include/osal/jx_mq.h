/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_mq.h
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

#ifndef _JX_MQ_H_
#define _JX_MQ_H_

#include <osal/jx_stdint.h>

typedef void *jx_mqhandle_t;

/**@struct jx_mq_para
* @brief message queue creation para structure
*/
struct jx_mq_para {
    jx_char_t *name;           /**message queue name,at most 8 char*/
    jx_u32_t msg_size;         /**message size*/
    jx_u32_t max_msgs;         /**dynamically create message queue,user needs to provide message max count*/
    jx_u8_t flag;              /**multi-threaded message acquisition mode, priority (1) or FIFO (0)*/
};
typedef struct jx_mq_para       jx_mq_para_t;
typedef struct jx_mq_para      *jx_pmq_para_t;

/**
* @brief create message queue dynamicly
* @param[in] pmq_para message queue creation para structure pointer
* @retval mq handle
*/
jx_mqhandle_t jx_mq_create(jx_pmq_para_t pmq_para);

/**
* @brief send message to message queue
* @param[in] handle message queue pointer
* @param[in] buffer pointer of message to send
* @param[in] size size of message to send
* @param[in] timeout wait for time
* @retval operation status
*/
jx_err_t jx_mq_send(jx_mqhandle_t handle, jx_void_t *buffer, jx_u32_t size, jx_s32_t timeout);

/**
* @brief send urgent message to message queue
* @param[in] handle message queue pointer
* @param[in] buffer pointer of message to send
* @param[in] size size of message to send
* @retval operation status
*/
jx_err_t jx_mq_urgent(jx_mqhandle_t handle, jx_void_t *buffer, jx_u32_t size);

/**
* @brief This function will receive a message from a message queue
* @param[in] handle is a pointer to a message queue
* @param[in] buffer is a pointer of a message to receive
* @param[in] size size of message to receive
* @param[in] timeout is a timeout period to receive a message
* @retval receive size
*/
jx_s32_t jx_mq_recv(jx_mqhandle_t handle, jx_void_t *buffer, jx_u32_t size, jx_s32_t timeout);

/**
* @brief delete message queue
* @param[in] pmqinfo message queue creation info structure pointer
* @retval operation status
*/
jx_err_t jx_mq_delete(jx_mqhandle_t handle);

#endif
