/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_err.h
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

#ifndef _JX_ERR_H_
#define _JX_ERR_H_

#define JX_OK                   0            /*No error*/
#define JX_ERROR                1            /*Regular error*/
#define JX_TIMEOUT              2            /*Timeout error*/
#define JX_FULL                 3            /*Resource is full*/
#define JX_EMPTY                4            /*No resource*/
#define JX_NOMEM                5            /*No memory*/
#define JX_NOSYS                6            /*System does not support*/
#define JX_BUSY                 7            /*System busy*/
#define JX_IO                   8            /*IO error*/
#define JX_INTR                 9            /*Interrupt system call*/
#define JX_INVAL                10           /*Invalid Parameter*/

#endif
