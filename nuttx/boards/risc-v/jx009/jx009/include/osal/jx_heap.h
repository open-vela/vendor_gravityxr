/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_heap.h
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

#ifndef _JX_HEAP_H_
#define _JX_HEAP_H_

#include <osal/jx_stdint.h>

typedef void *jx_mphandle_t;

/**@struct jx_mp_para
* @brief mempool creation para structure
*/
struct jx_mp_para {
    jx_char_t *name;             /**mempool name,at most 8 char*/
    jx_u32_t block_count;       /**dynamically create memory pool user supply memory block count*/
    jx_u32_t block_size;        /**memory block size*/
};
typedef struct jx_mp_para    jx_mp_para_t;
typedef struct jx_mp_para   *jx_pmp_para_t;

/**
 * @brief allocate a block of memory from system heap.
 * @param[in] size minimum size of the requested block in bytes
 * @retval pointer to allocated memory
 */
jx_void_t *jx_malloc(jx_u32_t size);

/**
 * @brief change the size of previously allocated memory block from system heap.
 * @param[in] pmem pointer to memory allocated.
 * @param[in] newsize required new size.
 * @retval changed memory block address.
 */
jx_void_t *jx_realloc(jx_void_t *pmem, jx_u32_t newsize);

/**
 * @brief release the previously allocated memory block from system heap.
 * @param[in] pmem address of memory which will be released.
 */
jx_void_t jx_free(jx_void_t *pmem);

/**
 * @brief allocate a block of memory which address is aligned to the specified alignment size.
 * @param[in] size allocated memory block size
 * @retval pointer to allocated memory
 */
jx_void_t *jx_malloc_align(jx_u32_t size, jx_u32_t align);

/**
 * @brief release the previously allocated memory block which is allocated by jx_malloc_align.
 * @param[in] pmem address of memory which will be released.
 */
jx_void_t jx_free_align(jx_void_t *pmem);

/**
* @brief create a mempool dynamicly
* @param[in] pmp_para pointer of mempool creation para structure
* @retval mp handle
*/
jx_mphandle_t jx_mp_create(jx_pmp_para_t pmp_para);

/**
* @brief allocate a mem block from mempool
* @param[in] handle pointer of mempool
* @param[in] timeout wait for time to allocate a mem block
* @retval pointer of a mem block
*/
jx_void_t *jx_mp_alloc(jx_mphandle_t handle, jx_s32_t timeout);

/**
* @brief free a mem block from mempool
* @param[in] block pointer of a mem block
* @retval operation status
*/
jx_err_t jx_mp_free(jx_mphandle_t handle, jx_void_t *block);

/**
* @brief delete a mempool
* @param[in] pmpinfo pointer of mempool creation info structure
* @retval operation status
*/
jx_err_t jx_mp_delete(jx_mphandle_t handle);

#endif
