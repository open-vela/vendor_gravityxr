/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_record.h
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

#ifndef _JX_RECORD_H_
#define _JX_RECORD_H_

#include <osal/jx_stdint.h>

enum jx_record_event {
    JX_EVENT_THREAD = 0,
    JX_EVENT_IRQ = 1
};

/**
* @brief schedule record interface
* @param[in] event record event
* @param[in] content record content
*/
jx_void_t jx_schedule_record(jx_u8_t event, jx_u8_t cpu_id, jx_u32_t content);

#endif