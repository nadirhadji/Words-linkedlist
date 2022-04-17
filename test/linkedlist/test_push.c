/**
 * @file test_push.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "linkedlist_init.h"

static Linkedlist* list;

void test_one_int_push() {
    int value = 1;
    push(list,&value);
    CU_ASSERT_EQUAL(*((int *)list->head->value),1);
    CU_ASSERT_TRUE(list->length==1);
}

void test_multiple_int_push() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(int);
    for( int i = 0 ; i < 5 ; ++i ) 
    {
        push(list,&array[i]);
        CU_ASSERT_TRUE( *( (int *) list->head->value ) == array[i] );
        printf("%d\n",list->length);
        CU_ASSERT_TRUE(list->length == (i+1));
    }   
}

void test_one_char_push() {
    char value = 'a';
    push(list,&value);
    CU_ASSERT_EQUAL(*((char *)list->head->value),'a');
    CU_ASSERT_TRUE(list->length==1);
}

void test_multiple_char_push() {
    int array[] = {'a','b','c','d','e'};
    int size = sizeof(char);
    for( int i = 0 ; i < 5 ; ++i ) 
    {
        push(list,&array[i]);
        CU_ASSERT_TRUE( *( (char *) list->head->value ) == array[i] );
        CU_ASSERT_TRUE(list->length == (i+1));
    } 
}   

void test_one_string_push() {
    char value[10] = "canada";
    push(list,value);
    char *buffer = (char *)(list->head->value);
    CU_ASSERT_STRING_EQUAL(buffer,value);
    CU_ASSERT_TRUE(list->length==1);
}

void test_multiple_string_push() {
    char array[5][10] = {"admin","tom","bob","tim","jim"};
    for( int i = 0 ; i < 5 ; ++i ) 
    {
        push(list,array[i]);
        char *buffer = (char *)(list->head->value);
        CU_ASSERT_STRING_EQUAL(array[i],buffer);
        CU_ASSERT_TRUE(list->length == (i+1));
    }
}

void test_int_add_inorder_worst() {
    int array[] = {50, 40, 30, 20, 10};
    for( int i = 0 ; i < 5 ; i++ ) 
        push_in_order(list,&array[i]);
    qsort(array,5,sizeof(int),int_compare);
    Node *head = (Node *)list->head;
    for (int j = 0 ; j < 5 ; ++j)
    {
        CU_ASSERT_TRUE( *( (int *) head->value ) == array[j] );
        head = head->next;
    }
    CU_ASSERT_TRUE(list->length == 5);
}

void test_int_add_inorder_mid() {
    int array[] = {40, 10, 30, 20, 50};
    for( int i = 0 ; i < 5 ; i++ ) 
        push_in_order(list,&array[i]);
    qsort(array,5,sizeof(int),int_compare);
    Node *head = (Node *)list->head;
    for (int j = 0 ; j < 5 ; ++j)
    {
        CU_ASSERT_TRUE( *( (int *) head->value ) == array[j] );
        head = head->next;
    }
    CU_ASSERT_TRUE(list->length == 5);
}

//Test configuration

int init_int_push()
{
    init_int_list(&list);
    return 0;
}

int init_char_push()
{
    init_char_list(&list);
    return 0;
}

int init_str_push()
{
    init_string_list(&list);
    return 0;
}

int destroy_push()
{
    free_linkedlist(&list);
    list->length = 0;
    list = NULL;
    free(list);
    return 0;
}

static CU_TestInfo testcases_int_push[] = {
    {"test_one_int_push",test_one_int_push},
    {"test_multiple_int_push",test_multiple_int_push},
    {"test_int_add_inorder",test_int_add_inorder_worst},
    {"test_int_add_inorder_mid",test_int_add_inorder_mid},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_char_push[] = {
    {"test_one_char_push",test_one_char_push},
    {"test_multiple_char_push",test_multiple_char_push},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_string_push[] = {
    {"test_one_string_push",test_one_string_push},
    {"test_multiple_string_push",test_multiple_string_push},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    {"Test int push in linkedlist", init_int_push, destroy_push, NULL, NULL, testcases_int_push},
    {"Test char push in linkedlist", init_char_push, destroy_push, NULL, NULL,  testcases_char_push},
    {"Test string push in linkedlist", init_str_push, destroy_push,  NULL, NULL,  testcases_char_push},
    CU_SUITE_INFO_NULL,
};

void add_push_tests(void) 
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for linkedlist - %s ", CU_get_error_msg());
        exit(1);
    }
}