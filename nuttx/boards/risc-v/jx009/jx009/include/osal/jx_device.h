/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_device.h
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

#ifndef _JX_DEVICE_H
#define _JX_DEVICE_H

#include <osal/jx_stdint.h>

#define JX_DEVICE_FLAG_RDONLY           0x001                 /**read only*/
#define JX_DEVICE_FLAG_WRONLY           0x002                 /**write only*/
#define JX_DEVICE_FLAG_RDWR             0x003                 /**read and write*/
#define JX_DEVICE_FLAG_REMOVABLE        0x004                 /**removable device*/
#define JX_DEVICE_FLAG_STANDALONE       0x008                 /**standalone device*/
#define JX_DEVICE_FLAG_SUSPENDED        0x020                 /**device is suspended*/
#define JX_DEVICE_FLAG_STREAM           0x040                 /**stream mode*/

#define JX_DEVICE_FLAG_INT_RX           0x100                 /**INT mode on Rx*/
#define JX_DEVICE_FLAG_DMA_RX           0x200                 /**DMA mode on Rx*/
#define JX_DEVICE_FLAG_INT_TX           0x400                 /**INT mode on Tx*/
#define JX_DEVICE_FLAG_DMA_TX           0x800                 /**DMA mode on Tx*/

#define JX_DEVICE_CTRL_RESUME           0x01                  /**resume device*/
#define JX_DEVICE_CTRL_SUSPEND          0x02                  /**suspend device*/
#define JX_DEVICE_CTRL_CONFIG           0x03                  /**configure device*/
#define JX_DEVICE_CTRL_CLOSE            0x03                  /**close device*/
#define JX_DEVICE_CTRL_SET_INT          0x10                  /**set interrupt*/
#define JX_DEVICE_CTRL_CLR_INT          0x11                  /**clear interrupt*/
#define JX_DEVICE_CTRL_GET_INT          0x12                  /**get interrupt status*/

typedef void *jx_devicehandle_t;

/**
 * @brief finds a device driver by specified name
 * @param[in] name device driver's name
 * @retval registered device driver
 */
jx_devicehandle_t jx_device_find(jx_char_t *name);

/**
 * @brief initialize the specified device
 * @param[in] dev pointer of device driver structure
 * @retval  operation state
 */
jx_err_t jx_device_init(jx_devicehandle_t handle);

/**
 * @brief open a device
 * @param[in] dev pointer of device driver structure
 * @param[in] oflag open flags for device
 * @retval operation status
 */
jx_err_t jx_device_open(jx_devicehandle_t handle, jx_u16_t oflag);

/**
 * @brief close a device
 * @param[in] dev pointer of device driver structure
 * @retval operation status
 */
jx_err_t jx_device_close(jx_devicehandle_t handle);

/**
 * @brief read some data from a device.
 * @param[in] dev pointer of device driver structure
 * @param[in] pos position of reading
 * @param[in] buffer data buffer to save read data
 * @param[in] size size of buffer
 * @retval actually read size.
 */
jx_u32_t jx_device_read(jx_devicehandle_t handle, jx_s32_t pos, jx_void_t *buffer, jx_u32_t size);

/**
 * @brief write some data to a device.
 * @param[in] dev pointer of device driver structure
 * @param[in] pos position of written
 * @param[in] buffer data buffer to be written to device
 * @param[in] size size of buffer
 * @retval actually written size
 */
jx_u32_t jx_device_write(jx_devicehandle_t handle, jx_s32_t pos, jx_void_t *buffer, jx_u32_t size);

/**
 * @brief perform a variety of control functions on devices
 * @param[in] dev pointer of device driver structure
 * @param[in] cmd command sent to device
 * @param[in] arg argument of command
 * @retval operation status
 */
jx_err_t jx_device_control(jx_devicehandle_t handle, jx_s32_t cmd, jx_void_t *arg);

#endif
