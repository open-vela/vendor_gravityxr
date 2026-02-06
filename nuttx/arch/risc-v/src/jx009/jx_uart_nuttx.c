/****************************************************************************
 * arch/risc-v/src/jx009/jx_uart_nuttx.c
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

#include "nuttx/serial/uart_snps.h"

#define CONSOLE_PTY_IO_BPS 250000

#define HW32_REG(ADDRESS)  (*((volatile unsigned long *)(ADDRESS)))

enum {
    CR      = '\r',
    LF      = '\n',
    TAB     = '\t',
    BLANK   = ' ',
    NC      = '\0',
    ON      = 1
};

static device_ins_t concole_pty_uart_base;

void nuttx_jx_console_output(const char *str)
{
    static uint8_t legacy = 0;

    const device_ins_t uart = concole_pty_uart_base;

    uint8_t outc = *str++;
    while (NC != outc) {
        if ((LF == outc) && (CR != legacy)) {
            jx_uart_putchar(uart, CR);
        }
        jx_uart_putchar(uart, outc);
        legacy = outc;

        outc = *str++;
    }
}

char nuttx_jx_console_getchar(void)
{
    const device_ins_t uart = concole_pty_uart_base;

    #if defined (UART_IO_MODE_INTERRUPT)
    #error "interrupt mode not supported right now!"

    #else/*!UART_IO_MODE_INTERRUPT*/
    do {
        int outc = jx_uart_getchar(uart, false);
        if (0 < outc) {
            return (char) outc;
        }
        //rt_thread_delay(1);
    } while (true);
    #endif/*UART_IO_MODE_INTERRUPT*/
}

int nuttx_jx_uart_init(void)
{
    device_ins_t uart = (device_ins_t) 0x7c006000;
    uart_config_t cfg = {
        .bps = CONSOLE_PTY_IO_BPS,
        .parity = UART_PARITY_NONE,
        .stop_bits = UART_STOPBITS_I,
        .data_bits = UART_DATABITS_VIII,
        .flow_ctrl = UART_FLOWCTRL_DISABLE
    };

    concole_pty_uart_base = uart;
    jx_uart_init(uart, &cfg);

    nuttx_jx_console_output("jx009 nuttx uart print init ok\n");
    return 0;
}
