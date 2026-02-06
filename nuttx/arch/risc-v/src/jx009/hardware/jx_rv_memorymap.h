/****************************************************************************
 * arch/risc-v/src/jx009/hardware/qemu_rv_memorymap.h
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

#ifndef __ARCH_RISCV_SRC_JX009_HARDWARE_JX009_MEMORYMAP_H
#define __ARCH_RISCV_SRC_JX009_HARDWARE_JX009_MEMORYMAP_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Base Address ****************************************************/

#ifdef CONFIG_ARCH_CHIP_JX009_PLIC
#  define JX009_PLIC_BASE    CONFIG_ARCH_CHIP_JX009_PLIC
#else
#  define JX009_PLIC_BASE    0x79000000
#endif

#ifdef CONFIG_ARCH_CHIP_JX009_CLINT
#  define JX009_CLINT_BASE   CONFIG_ARCH_CHIP_JX009_CLINT
#else
#  define JX009_CLINT_BASE   0x79400000
#endif

#ifdef CONFIG_ARCH_CHIP_JX009_ACLINT
#  define JX009_ACLINT_BASE  CONFIG_ARCH_CHIP_JX009_ACLINT
#else
#  define JX009_ACLINT_BASE  0x2f00000
#endif

#define   JX009_RESET_BASE   0x100000

#ifdef CONFIG_ARCH_USE_S_MODE
#  define JX009_APLIC_BASE   0x0d000000
#  define JX009_IMSIC_BASE   0x28000000
#else
#  define JX009_APLIC_BASE   0x0c000000
#  define JX009_IMSIC_BASE   0x24000000
#endif

#endif /* __ARCH_RISCV_SRC_JX009_HARDWARE_JX009_MEMORYMAP_H */
