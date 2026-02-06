/****************************************************************************
 * boards/risc-v/jx009/jx009/include/gxrlog.h
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

#ifndef __GXRLOG_H__
#define __GXRLOG_H__

#include <syslog.h>


/******************** User Level Definitions *********************/

#define LOG_LEVEL_ASSERT                                (0)       /* Unhandled and fatal errors occurred  */
#define LOG_LEVEL_ALERT                                 (1)       /* Action must be taken immediately     */
#define LOG_LEVEL_CRITICAL                              (2)       /* Critical conditions                  */
#define LOG_LEVEL_ERROR                                 (3)       /* Error conditions                     */
#define LOG_LEVEL_WARNING                               (4)       /* Warning conditions                   */
#define LOG_LEVEL_NOTICE                                (5)       /* Normal but significant condition     */
#define LOG_LEVEL_INFO                                  (6)       /* Normal Informational                 */
#define LOG_LEVEL_DEBUG                                 (7)       /* Debug-level messages                 */

/******************** User API Definitions *********************/

#define GXRLOG_PRINT(FORMAT, ...)                       syslog(FORMAT, ##__VA_ARGS__)

#define GXRLOG_PR_EMERG(NAME,  FORMAT, ...)             syslog(LOG_EMERG,   "[F]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_ALERT(NAME,  FORMAT, ...)             syslog(LOG_ALERT,   "[A]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_CRIT(NAME,   FORMAT, ...)             syslog(LOG_CRIT,    "[C]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_ERR(NAME,    FORMAT, ...)             syslog(LOG_ERR,     "[E]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_WARN(NAME,   FORMAT, ...)             syslog(LOG_WARNING, "[W]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_NOTICE(NAME, FORMAT, ...)             syslog(LOG_NOTICE,  "[N]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_INFO(NAME,   FORMAT, ...)             syslog(LOG_INFO,    "[I]" " [" NAME "] " FORMAT, ##__VA_ARGS__)
#define GXRLOG_PR_DEBUG(NAME,  FORMAT, ...)             syslog(LOG_DEBUG,   "[D]" " [" NAME "] " FORMAT, ##__VA_ARGS__)

#endif /* __GXRLOG_H__ */
