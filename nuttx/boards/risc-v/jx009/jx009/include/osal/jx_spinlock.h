/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_spinlock.h
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

#ifndef _JX_SPINLOCK_H_
#define _JX_SPINLOCK_H_

#include <osal/jx_stdint.h>

/**
 * @brief initialize spinlock.
 * @param[in] lock spinlock pointer.
 */
jx_handle_t jx_spin_lock_create(jx_void_t);

/**
* @brief lock spinlock.
* @param[in] lock spinlock pointer.
*/
jx_void_t jx_spin_lock(jx_handle_t lock);

/**
* @brief unlock spinlock.
* @param[in] lock spinlock pointer.
*/
jx_void_t jx_spin_unlock(jx_handle_t lock);

/**
* @brief disable the local interrupt, lock the spinlock, lock the thread scheduler.
* @param[in] lock spinlock pointer.
* @retval current cpu interrupt status.
*/
jx_u32_t jx_spin_lock_irq_save(jx_handle_t lock);

/**
* @brief unlock the spinlock, restore current cpu interrupt status, unlock the thread scheduler.
* @param[in] lock spinlock pointer.
* @param[in] level interrupt status.
*/
jx_void_t jx_spin_unlock_irq_restore(jx_handle_t lock, jx_u32_t level);

/**
* @brief destroy spinlock
* @param[in] lock spinlock pointer.
*/
jx_void_t jx_spin_lock_destroy(jx_handle_t lock);

#endif