/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_irq.h
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

#ifndef _JX_IRQ_H_
#define _JX_IRQ_H_

#include "jx_stdint.h"

//JX original: typedef jx_void_t (*jx_isr_handler_t)(jx_int_t irq_num, jx_void_t *param);
//Nuttx: typedef CODE int (*xcpt_t)(int irq, FAR void *context, FAR void *arg);
//new defined, to match with nuttx's xcpt_t
typedef jx_int_t (*jx_isr_handler_t)(jx_int_t irq_num, jx_void_t *context, jx_void_t *param);

enum jx_irq_triger_mode {
    JX_IRQ_TRIGER_MODE_LEVEL = 0,       /**level triger*/
    JX_IRQ_TRIGER_MODE_EDGE  = 1        /**edge triger*/
};

/**@struct jx_irq_para
* @brief irq install para structure
*/
struct jx_irq_para {
    jx_u32_t                   prio;                          /**irq priority*/
    enum jx_irq_triger_mode    triger_mode;                   /**irq triger mode*/
#ifdef JX_USING_SMP
    jx_u32_t                   cpu_mask;                      /**irq cpu mask bit*/
#endif
    jx_void_t                  *para;                         /**irq parameter*/
    jx_isr_handler_t           handler;                       /**irq handler*/
};
typedef struct jx_irq_para jx_irq_para_t;

/**
* @brief install irq
* @param[in] irq_num irq number
* @param[in] irq_para irq parameter
*/
jx_void_t jx_irq_install(jx_u32_t irq_num, jx_irq_para_t *irq_para);

/**
* @brief enable irq
* @param[in] irq_num irq number
*/
jx_void_t jx_irq_enable(jx_u32_t irq_num);

/**
* @brief disable irq
* @param[in] irq_num irq number
*/
jx_void_t jx_irq_disable(jx_u32_t irq_num);

/**
* @brief clear irq pending flag
* @param[in] irq_num irq number
*/
jx_void_t jx_irq_pending_clear(jx_u32_t irq_num);

/**
* @brief add isr bottom half to isr queue to handle by other threads
* @param[in] irq_num irq number
* @param[in] isr_func irq service routine func
* @param[in] irq_para irq parameter
*/
jx_s32_t jx_isrqueue_do(jx_u32_t irq_num, void (*isr_func)(jx_u32_t irq_para), jx_u32_t irq_para);

#endif
