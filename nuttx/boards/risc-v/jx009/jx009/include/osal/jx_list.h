/****************************************************************************
 * boards/risc-v/jx009/jx009/include/osal/jx_list.h
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

#ifndef _JX_LIST_H_
#define _JX_LIST_H_

#include <osal/jx_stdint.h>

/**@struct jx_list_node
* @brief list node structrue
*/
struct jx_list_node {
    struct jx_list_node *next;                          /**point to next node*/
    struct jx_list_node *prev;                          /**point to prev node*/
};
typedef struct jx_list_node jx_list_t;

/**
 * @brief initialize a list
 */
#define JX_LIST_INIT(list) { &(list), &(list) }

#define jx_container_of(ptr, type, member) \
((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))  /**return the start address of struct type*/

/**
* @brief get the struct for this entry
* @param[in] node the entry point
* @param[in] type the type of structure
* @param[in] member the name of list in structure
* @retval return struct pointer
*/
#define jx_list_entry(node, type, member) \
jx_container_of(node, type, member) /**get the struct for this entry*/

/**
* @brief get the struct for this entry
* @param[in] node the entry point
* @param[in] type1 the type of structure
* @param[in] member1 the name of list in structure
* @param[in] type2 the type of structure
* @param[in] member2 the name of list in structure
* @retval return struct pointer
*/
#define jx_list_entry_nest(node, type1, member1, type2, member2)    \
    jx_container_of(                           \
        jx_list_entry((node), type1, member1), \
        type2, member2)

/**
 * @brief iterate over a list
 * @param[in&out] pos  the jx_list_t* to use as a loop cursor.
 * @param[in] head  the head for your list.
 */
#define jx_list_for_each(pos, head) \
for (pos = (head)->next; pos != (head); pos = pos->next)   /**iterate over a list*/

/**
 * @brief iterate over a list safe against removal of list entry
 * @param[in&out] pos  the jx_list_t* to use as a loop cursor.
 * @param[in&out] n  another jx_list_t* to use as temporary storage
 * @param[in] head  the head for your list.
 */
#define jx_list_for_each_safe(pos, n, head) \
for (pos = (head)->next, n = pos->next; pos != (head); \
pos = n, n = pos->next)        /**iterate over a list safe against removal of list entry*/

/**
 * @brief iterate over list of given type
 * @param[in&out] pos the type* to use as a loop cursor.
 * @param[in] head the head for your list.
 * @param[in] member the name of the list_struct within the struct.
 */
#define jx_list_for_each_entry(pos, head, member) \
for (pos = jx_list_entry((head)->next, typeof(*pos), member); \
&pos->member != (head); \
pos = jx_list_entry(pos->member.next, typeof(*pos), member)) /**iterate over list of given type*/

/**
 * @brief iterate over list of given type safe against removal of list entry
 * @param[in&out] pos the type* to use as a loop cursor.
 * @param[in&out] n another type* to use as temporary storage
 * @param[in] head the head for your list.
 * @param[in] member the name of the list_struct within the struct.
 */
#define jx_list_for_each_entry_safe(pos, n, head, member) \
for (pos = jx_list_entry((head)->next, typeof(*pos), member), \
    n = jx_list_entry(pos->member.next, typeof(*pos), member); \
    &pos->member != (head); \
    pos = n, n = jx_list_entry(n->member.next, typeof(*n), member)) /**iterate over list of given type safe against removal of list entry*/

/**
 * @brief get the first element from a list
 * @param ptr[in] the list head to take the element from.
 * @param[in] type the type of the struct this is embedded in.
 * @param[in] member the name of the list_struct within the struct.
 * @retval the first element from a list
 * @note: that list is expected to be not empty.
 */
#define jx_list_first_entry(ptr, type, member) \
        jx_list_entry((ptr)->next, type, member)  /**get the first element from a list*/

/**
 * @brief initialize a list
 * @param[in] l list pointer
 */
jx_void_t jx_list_init(jx_list_t *l);

/**
 * @brief insert a node after a list
 * @param[in] l list pointer
 * @param[in] n node pointer to be inserted
 */
jx_void_t jx_list_insert_after(jx_list_t *l, jx_list_t *n);

/**
 * @brief insert a node before a list
 * @param[in] l list pointer
 * @param[in] n node pointer to be inserted
 */
jx_void_t jx_list_insert_before(jx_list_t *l, jx_list_t *n);

/**
 * @brief remove node from list
 * @param[in] n node pointer to remove from the list
 */
jx_void_t jx_list_remove(jx_list_t *n);

/**
 * @brief tests whether a list is empty
 * @param[in] l list pointer
 * @retval flag whether a list is empty
 */
jx_s32_t jx_list_isempty(jx_list_t *l);

/**
 * @brief get the list length
 * @param[in] l list pointer
 * @retval list length
 */
jx_u32_t jx_list_len(jx_list_t *l);

#endif
