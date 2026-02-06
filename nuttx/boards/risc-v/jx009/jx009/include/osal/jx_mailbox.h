/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_mailbox.h
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

#ifndef _JX_MAILBOX_H_
#define _JX_MAILBOX_H_

#include <osal/jx_stdint.h>

typedef void *jx_mbhandle_t;

/**@struct jx_mb_para
* @brief mailbox creation para structure
*/
struct jx_mb_para {
    jx_char_t *name;             /**mailbox name,at most 8 char*/
    jx_u32_t size;               /**count of stored data in mailbox*/
    jx_u8_t flag;                /**multi-threaded mailbox acquisition mode, priority (1) or FIFO (0)*/
};
typedef struct jx_mb_para       jx_mb_para_t;
typedef struct jx_mb_para      *jx_pmb_para_t;

/**
* @brief create mailbox dynamicly
* @param[in] pmb_para mailbox creation para structrue pointer
* @retval mb handle
*/
jx_mbhandle_t jx_mb_create(jx_pmb_para_t pmb_para);

/**
* @brief send value to mailbox
* @param[in] handle mailbox pointer
* @param[in] value send data
* @param[in] timeout wait for time
* @retval operation status
*/
jx_err_t jx_mb_send(jx_mbhandle_t handle, jx_u32_t value, jx_s32_t timeout);

/**
* @brief send urgent value to mailbox
* @param[in] handle mailbox pointer
* @param[in] value urgent data to send
* @retval operation status
*/
jx_err_t jx_mb_urgent(jx_mbhandle_t handle, jx_u32_t value);

/**
* @brief receive content from mailbox
* @param[in] handle mailbox pointer
* @param[in] value pointer of data to recv
* @param[in] timeout wait for time
* @retval operation status
*/
jx_err_t jx_mb_recv(jx_mbhandle_t handle, jx_u32_t *value, jx_s32_t timeout);

/**
* @brief delete mailbox
* @param[in] pmbinfo mailbox creation info structrue pointer
* @retval operation status
*/
jx_err_t jx_mb_delete(jx_mbhandle_t handle);

#endif
