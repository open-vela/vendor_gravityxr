# ##############################################################################
# arch/risc-v/src/jx009/CMakeLists.txt
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

set(SRCS jx_rv_head.S)

list(
  APPEND
  SRCS
  jx_rv_start.c
  jx_rv_irq_dispatch.c
  jx_rv_irq.c
  jx_rv_timerisr.c
  jx_rv_allocateheap.c)

if(CONFIG_BUILD_KERNEL)
elseif(CONFIG_BUILD_PROTECTED)
  list(APPEND SRCS jx_rv_userspace.c)
endif()

if(CONFIG_MM_PGALLOC)
  list(APPEND SRCS jx_rv_pgalloc.c)
endif()

if(CONFIG_BUILD_PROTECTED)
  list(APPEND SRCS jx_rv_userspace.c)
endif()

if(CONFIG_RPTUN)
  list(APPEND SRCS jx_rv_rptun.c)
endif()

if(CONFIG_SNPS_UART)
  list(APPEND SRCS jx_uart_nuttx.c)
endif()

target_sources(arch PRIVATE ${SRCS})
