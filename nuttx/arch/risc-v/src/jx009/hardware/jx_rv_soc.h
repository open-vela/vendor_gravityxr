/**
 * @file       nuttx/arch/risc-v/src/jx009/hardware/jx_rv_soc.h
 * @copyright  Copyright (C) 2026 by GravityXR Electronics and Technology Co., Ltd. All rights reserved.
 * @brief      GravityXR JX SOC definitions
 * @author     gravityxr.cn
 * @date       2026-1-17
 * @version    v0.1
 */


#ifndef __ARCH_RISCV_SRC_JX009_HARDWARE_JX009_SOC_H
#define __ARCH_RISCV_SRC_JX009_HARDWARE_JX009_SOC_H

#define TIMER_COST_COEFFICIENT  (93)

#if defined(CONFIG_JX009_CORE_AON)
#define MTIMER_FREQ (2500000 * TIMER_COST_COEFFICIENT)
#elif defined(CONFIG_JX009_CORE_RAZOR)
#define MTIMER_FREQ (1000000 * TIMER_COST_COEFFICIENT)
#endif

#define TICK_COUNT (MTIMER_FREQ / TICK_PER_SEC)

#endif
