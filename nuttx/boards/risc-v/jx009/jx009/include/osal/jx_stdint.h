/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_stdint.h
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

#ifndef _JX_STDINT_H_
#define _JX_STDINT_H_

#include <stdint.h>
#include <stdbool.h>

typedef int8_t                  jx_s8_t;
typedef int16_t                 jx_s16_t;
typedef int32_t                 jx_s32_t;
typedef int64_t                 jx_s64_t;
typedef uint8_t                 jx_u8_t;
typedef uint16_t                jx_u16_t;
typedef uint32_t                jx_u32_t;
typedef uint64_t                jx_u64_t;

typedef bool                    jx_bool_t;
typedef char                    jx_char_t;
typedef void                    jx_void_t;
typedef int                     jx_err_t;
typedef void                   *jx_handle_t;

typedef int                     jx_int_t;
typedef unsigned int            jx_uint_t;

typedef float                   jx_float_t;
typedef double                  jx_double_t;

#define JX_TRUE                 1
#define JX_FALSE                0
#define JX_NULL                 0

#ifndef NULL
#define NULL                    JX_NULL
#endif

#endif
