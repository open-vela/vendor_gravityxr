/****************************************************************************
 * boards/risc-v/jx009/jx009/src/jx009_rv_appinit.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdbool.h>
#include <stdio.h>
#include <syslog.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/board.h>
#include <nuttx/drivers/ramdisk.h>
#include <nuttx/virtio/virtio-mmio.h>

#include <sys/mount.h>

#include "riscv_sbi.h"
#include "romfs.h"
#include "jx_uart.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/


#define SECTORSIZE   512
#define NSECTORS(b)  (((b) + SECTORSIZE - 1) / SECTORSIZE)

/****************************************************************************
 * Private Functions
 ****************************************************************************/


/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_app_initialize
 *
 * Description:
 *   Perform architecture specific initialization
 *
 * Input Parameters:
 *   arg - The boardctl() argument is passed to the board_app_initialize()
 *         implementation without modification.  The argument has no
 *         meaning to NuttX; the meaning of the argument is a contract
 *         between the board-specific initialization logic and the
 *         matching application logic.  The value could be such things as a
 *         mode enumeration value, a set of DIP switch switch settings, a
 *         pointer to configuration data read from a file or serial FLASH,
 *         or whatever you would like to do with it.  Every implementation
 *         should accept zero/NULL as a default configuration.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure to indicate the nature of the failure.
 *
 ****************************************************************************/

int board_app_initialize(uintptr_t arg)
{
#ifdef CONFIG_BOARD_LATE_INITIALIZE
  /* Board initialization already performed by board_late_initialize() */

  return OK;
#else
  /* Perform board-specific initialization */

#ifdef CONFIG_NSH_ARCHINIT

#ifdef CONFIG_FS_PROCFS
  mount(NULL, "/proc", "procfs", 0, NULL);
#endif

#ifdef CONFIG_FS_TMPFS
  mount(NULL, CONFIG_LIBC_TMPDIR, "tmpfs", 0, NULL);
#endif

#endif

#ifdef CONFIG_RPTUN
  qemu_rptun_init();
#endif
  return OK;
#endif
}

/****************************************************************************
 * Name: board_late_initialize
 *
 * Description:
 *   If CONFIG_BOARD_LATE_INITIALIZE is selected, then an additional
 *   initialization call will be performed in the boot-up sequence to a
 *   function called board_late_initialize().  board_late_initialize() will
 *   be called after up_initialize() and board_early_initialize() and just
 *   before the initial application is started.  This additional
 *   initialization phase may be used, for example, to initialize board-
 *   specific device drivers for which board_early_initialize() is not
 *   suitable.
 *
 *   Waiting for events, use of I2C, SPI, etc are permissible in the context
 *   of board_late_initialize().  That is because board_late_initialize()
 *   will run on a temporary, internal kernel thread.
 *
 ****************************************************************************/

void board_late_initialize(void)
{
  /* Perform board-specific initialization */

#if defined(CONFIG_BUILD_KERNEL) && !defined(CONFIG_RISCV_SEMIHOSTING_HOSTFS)
  /* Create ROM disk for mount in nx_start_application */

  if (NSECTORS(romfs_img_len) > 1)
    {
      int ret = OK;
      ret = romdisk_register(0, romfs_img, NSECTORS(romfs_img_len),
        SECTORSIZE);
      if (ret < 0)
        {
          ferr("ERROR: Failed to register romfs: %d\n", -ret);
        }
    }
#endif /* CONFIG_BUILD_KERNEL && !CONFIG_RISCV_SEMIHOSTING_HOSTFS */

#ifdef CONFIG_NSH_ARCHINIT

  mount(NULL, "/proc", "procfs", 0, NULL);

#endif

}

void board_early_initialize(void)
{
}

#ifdef CONFIG_BOARDCTL_POWEROFF
int board_power_off(int status)
{
#if defined(CONFIG_BUILD_KERNEL) && ! defined(CONFIG_NUTTSBI)
  riscv_sbi_system_reset(SBI_SRST_TYPE_SHUTDOWN, SBI_SRST_REASON_NONE);
#else
  *(volatile uint32_t *)JX_RV_RESET_BASE = JX_RV_RESET_DONE;
#endif

  UNUSED(status);
  return 0;
}
#endif

__attribute__((weak)) int nsh_main(int argc, char *argv[])
{
  int ret = 0;
#if defined(CONFIG_SNPS_UART)
  nuttx_jx_console_output(CONFIG_BASE_DEFCONFIG);
  nuttx_jx_console_output(" - nuttx conf starts ok\n");
#endif

  nsh_initialize();

#if defined(CONFIG_ARCH_CHIP_JX009)
  extern void jx_self_test(void);
  //jx_self_test();
#endif

#ifdef CONFIG_NSH_CONSOLE
  ret = nsh_consolemain(argc, argv);
  /* nsh_consolemain() should not return.  So if we get here, something
   * is wrong.
   */
  ret = 1;
#endif
  return ret;
}

__attribute__((weak)) void up_putc(int ch)
{

}
