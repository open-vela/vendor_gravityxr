/****************************************************************************
 * arch/risc-v/include/jx009/irq.h
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

#ifndef __ARCH_RISCV_INCLUDE_JX009_IRQ_H
#define __ARCH_RISCV_INCLUDE_JX009_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <arch/irq.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Map RISC-V exception code to NuttX IRQ */

#define JX009_IRQ_SOC_OFFSET        (RISCV_IRQ_MEXT + 1)

/* -------------------------  Interrupt Number Definition  ------------------------ */

/* -------------------  Processor Interrupt Numbers  ------------------------------ */
/* !!!Attention: Andes RISCV CPU requires starting from 1, all soc  */
#define IRQ_COMBINE_AHB_DMAC0 (JX009_IRQ_SOC_OFFSET + 0) /*  AHB_DMAC0 interrupt */
#define IRQ_COMBINE_AHB_DMAC1 (JX009_IRQ_SOC_OFFSET + 1) /*  AHB_DMAC1 interrupt */
#define IRQ_I2C0              (JX009_IRQ_SOC_OFFSET + 2) /*  APB I2C0 interrupt */
#define IRQ_I2C1              (JX009_IRQ_SOC_OFFSET + 3) /*  APB I2C1 interrupt */
#define IRQ_I2C2              (JX009_IRQ_SOC_OFFSET + 4) /*  APB I2C2 interrupt */
#define IRQ_I2C3              (JX009_IRQ_SOC_OFFSET + 5) /*  APB I2C3 interrupt */
#define IRQ_I2S               (JX009_IRQ_SOC_OFFSET + 6) /*  APB I2S interrupt */
#define IRQ_UART_INTR0        (JX009_IRQ_SOC_OFFSET + 7) /*  APB UART0 interrupt */
#define IRQ_UART_INTR1        (JX009_IRQ_SOC_OFFSET + 8) /*  APB UART1 interrupt */
#define IRQ_UART_INTR2        (JX009_IRQ_SOC_OFFSET + 9) /*  APB UART2 interrupt */
#define IRQ_PWM0              (JX009_IRQ_SOC_OFFSET + 10) /*  APB PWM0 interrupt */
#define IRQ_PWM1              (JX009_IRQ_SOC_OFFSET + 11) /*  APB PWM1 interrupt */
#define IRQ_PWM2              (JX009_IRQ_SOC_OFFSET + 12) /*  APB PWM2 interrupt */
#define IRQ_PWM3              (JX009_IRQ_SOC_OFFSET + 13) /*  APB PWM3 interrupt */

#if defined(CONFIG_JX009_CORE_RAZOR)
#define IRQ_IPC_A45_A45       (JX009_IRQ_SOC_OFFSET + 14) /*  IPC  a45 to a45 */
#define IRQ_IPC_N25F_A45      (JX009_IRQ_SOC_OFFSET + 15) /*  IPC  n25 to a45 */
#endif

#if defined(CONFIG_JX009_CORE_AON)
#define IRQ_IPC_N25F_N25F     (JX009_IRQ_SOC_OFFSET + 14) /*  IPC  n25 to n25 */
#define IRQ_IPC_A45_N25F      (JX009_IRQ_SOC_OFFSET + 15) /*  IPC  a45 to n25 */
#endif

#define IRQ_JTAGCTL_DBG_WAKEUP (JX009_IRQ_SOC_OFFSET + 16) /*  debugtrace wakeup interrupt */
#define IRQ_TIMER_INTR0       (JX009_IRQ_SOC_OFFSET + 17) /*  APB timer interrupt0 */
#define IRQ_TIMER_INTR1       (JX009_IRQ_SOC_OFFSET + 18) /*  APB timer interrupt1 */
#define IRQ_TIMER_INTR2       (JX009_IRQ_SOC_OFFSET + 19) /*  APB timer interrupt2 */
#define IRQ_TIMER_INTR3       (JX009_IRQ_SOC_OFFSET + 20) /*  APB timer interrupt3 */
#define IRQ_TIMER_INTR4       (JX009_IRQ_SOC_OFFSET + 21) /*  APB timer interrupt4 */
#define IRQ_TIMER_INTR5       (JX009_IRQ_SOC_OFFSET + 22) /*  APB timer interrupt5 */
#define IRQ_TIMER_INTR6       (JX009_IRQ_SOC_OFFSET + 23) /*  APB timer interrupt6 */
#define IRQ_TIMER_INTR7       (JX009_IRQ_SOC_OFFSET + 24) /*  APB timer interrupt7 */
#define IRQ_GPIO_INTR1        (JX009_IRQ_SOC_OFFSET + 25) /*  DW_apb_gpio inst1 interrupt */
#define IRQ_GPIO_INTR2        (JX009_IRQ_SOC_OFFSET + 26) /*  DW_apb_gpio inst2 interrupt */
#define IRQ_GPIO_INTR3        (JX009_IRQ_SOC_OFFSET + 27) /*  DW_apb_gpio inst3 interrupt */
#define IRQ_SPI_INTR0         (JX009_IRQ_SOC_OFFSET + 28) /*  DW_apb_ssi spi0 interrupt */
#define IRQ_QSPI_INTR0        (JX009_IRQ_SOC_OFFSET + 29) /*  DWC_ssi qspi inst0 interrupt */
#define IRQ_QSPI_INTR1        (JX009_IRQ_SOC_OFFSET + 30) /*  DWC_ssi qspi inst1 interrupt */
#define IRQ_RTC               (JX009_IRQ_SOC_OFFSET + 31) /*  DW_apb_rtc interrupt */
#define IRQ_USB               (JX009_IRQ_SOC_OFFSET + 62) /*  Crogine usb interrupt */
#define IRQ_NPU               (JX009_IRQ_SOC_OFFSET + 63) /*  NPU interrupt */
#define IRQ_TIMESTAMP         (JX009_IRQ_SOC_OFFSET + 65) /*  timestamp interrupt */
#define IRQ_SPI_INTR1         (JX009_IRQ_SOC_OFFSET + 74) /*  DW_apb_ssi spi1 interrupt */
#define IRQ_SPI_INTR2         (JX009_IRQ_SOC_OFFSET + 75) /*  DW_apb_ssi spi2 interrupt */
#define IRQ_SPI_INTR3         (JX009_IRQ_SOC_OFFSET + 76) /*  DW_apb_ssi spi3 interrupt */
#define IRQ_SPI_INTR4         (JX009_IRQ_SOC_OFFSET + 77) /*  DW_apb_ssi spi3 interrupt */
#define IRQ_TIMER_INTR8       (JX009_IRQ_SOC_OFFSET + 78) /*  AON timer interrupt0 */
#define IRQ_TIMER_INTR9       (JX009_IRQ_SOC_OFFSET + 79) /*  AON timer interrupt1 */
#define IRQ_TIMER_INTR10      (JX009_IRQ_SOC_OFFSET + 80) /*  AON timer interrupt2 */
#define IRQ_TIMER_INTR11      (JX009_IRQ_SOC_OFFSET + 81) /*  AON timer interrupt3 */
#define IRQ_TIMER_INTR12      (JX009_IRQ_SOC_OFFSET + 82) /*  AON timer interrupt4 */
#define IRQ_TIMER_INTR13      (JX009_IRQ_SOC_OFFSET + 83) /*  AON timer interrupt5 */
#define IRQ_TIMER_INTR14      (JX009_IRQ_SOC_OFFSET + 84) /*  AON timer interrupt6 */
#define IRQ_TIMER_INTR15      (JX009_IRQ_SOC_OFFSET + 85) /*  AON timer interrupt7 */
#define IRQ_GPIO_INTR0        (JX009_IRQ_SOC_OFFSET + 86) /*  DW_apb_gpio inst0 interrupt(AON) */
#define IRQ_PMU_INTR          (JX009_IRQ_SOC_OFFSET + 87) /*  PMU interrupt */
#define IRQ_QSPI_INTR2        (JX009_IRQ_SOC_OFFSET + 99) /*  DWC_ssi qspi inst2 interrupt */
#define IRQ_GPIO_INTR4        (JX009_IRQ_SOC_OFFSET + 102) /*  DW_apb_gpio inst4 interrupt */

#define IRQ_NUM_MAX           (JX009_IRQ_SOC_OFFSET + 128)

#define JX009_IRQ_UART0  (IRQ_UART_INTR0)

#define NR_IRQS (IRQ_NUM_MAX - 1)
#define RISCV_MAX_EXCEPTION (-1)

#endif /* __ARCH_RISCV_INCLUDE_JX009_IRQ_H */
