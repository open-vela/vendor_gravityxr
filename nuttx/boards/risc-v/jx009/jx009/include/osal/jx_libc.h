/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_libc.h
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

#ifndef _JX_LIBC_H_
#define _JX_LIBC_H_

#include <osal/jx_stdint.h>

/**
* @brief set the content of memory to specified value
* @param[in] mem memory address
* @param[in] value memory value to set
* @param[in] count memory size
*/
jx_void_t jx_memset(jx_void_t *mem, jx_s32_t value, jx_u32_t count);

/**
* @brief copy source memory value to destination memory
* @param[in] dst destination memory address
* @param[in] src source memory address
* @param[in] count memory size
*/
jx_void_t jx_memcpy(jx_void_t *dst, const jx_void_t *src, jx_u32_t count);

/**
* @brief memory value compare
* @param[in] mem1 first memory address
* @param[in] mem2 second memory address
* @param[in] count memory size
* @retval compare result
* If the result < 0, mem1 is smaller than mem2.
* If the result > 0, mem1 is greater than mem2.
* If the result = 0, mem1 is equal to mem2.
*/
jx_s32_t jx_memcmp(jx_void_t *mem1, jx_void_t *mem2, jx_u32_t count);

/**
* @brief copy source address string to destination address
* @param[in] dst destination string address
* @param[in] src source string address
* @param[in] count memory size
*/
jx_void_t jx_strncpy(jx_char_t *dst, jx_char_t *src, jx_u32_t count);

/**
* @brief string compare
* @param[in] str1 first string address
* @param[in] str2 second string address
* @param[in] count string size
* @retval compare result
* If the result < 0, str1 is smaller than str2
* If the result > 0, str1 is greater than str2
* If the result = 0, str1 is equal to str2
*/
jx_s32_t jx_strncmp(jx_char_t *str1, jx_char_t *str2, jx_u32_t count);

/**
* @brief get size of string
* @param[in] str string address
* @retval string size
*/
jx_u32_t jx_strlen(jx_char_t *str);

/**
 * @brief  fill a formatted string to buffer
 * @param  buf the buffer to save formatted string
 * @param  format format parameters
 * @retval The number of characters actually written to buffer
 */
jx_s32_t jx_sprintf(jx_char_t *buf, jx_char_t *fmt, ...);

/**
 * @brief  fill a formatted string to buffer to special size
 * @param  buf the buffer to save formatted string
 * @param  size is the size of buffer
 * @param  format format parameters
 * @retval The number of characters actually written to buffer
 */
jx_s32_t jx_snprintf(jx_char_t *buf, jx_u32_t size, jx_char_t *fmt, ...);

/**
 * @brief print a formatted string
 * @param fmt format parameters
 * @retval number of characters actually written to buffer.
 */
jx_s32_t jx_printf(const jx_char_t *fmt, ...);

#endif