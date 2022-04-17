/**
 * @file test_linkedlist.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TEST_LINKED_LIST
#define TEST_LINKED_LIST

#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "CUnit/Basic.h"
#include "../../src/linkedlist/linkedlist.h"
#include "../../src/extractor/extractor.h"

int int_compare( void *a,  void *b);

int char_compare( void *a,  void *b );

int str_compare(void *a,  void *b);

void free_data();

void str_print(void *str);

void int_print(void *num);

void char_print(void *num);

int init_int_list(Linkedlist **list);

int init_char_list(Linkedlist **list);

int init_string_list(Linkedlist **list);

int init_full_string_list(Linkedlist **list);

int init_full_int_list(Linkedlist **list);

int init_full_char_list(Linkedlist **list);

int cleanup(Linkedlist **list);

#endif