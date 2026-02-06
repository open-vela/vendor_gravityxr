/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_macros.h
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

#ifndef _JX_MACROS_H_
#define _JX_MACROS_H_

#ifdef RTOS_OSAL
#include <rtthread.h>

#ifndef JX_ASSERT
#define JX_ASSERT  RT_ASSERT
#endif

#ifndef JX_UNUSED
#define JX_UNUSED  RT_UNUSED
#endif

#ifndef JX_CPU_MASK
#define JX_CPU_MASK  RT_CPU_MASK
#endif

#ifndef JX_IPC_FLAG_FIFO
#define JX_IPC_FLAG_FIFO  RT_IPC_FLAG_FIFO
#endif

#ifndef JX_IPC_FLAG_PRIO
#define JX_IPC_FLAG_PRIO  RT_IPC_FLAG_PRIO
#endif

#endif  /**RTOS_OSAL*/

#endif  /**_JX_MACROS_H_*/