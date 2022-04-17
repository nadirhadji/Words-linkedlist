/**
 * @file test_linkedlist.c
 * @author Nadir Hadji
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "linkedlist_init.h"

static Linkedlist *list;

//Tests for the create méthode
void test_create() {
    printf("im here\n");
    CU_ASSERT_TRUE(list->length == 0);
    CU_ASSERT_TRUE(list->head == NULL);
    CU_ASSERT_TRUE(list != NULL);
}

//Tests for the free méthode
void test_free() {
    CU_ASSERT_PTR_NOT_NULL(list);
    free_linkedlist(list);
    CU_ASSERT_EQUAL(list->length,0);
}

//Test configuration

int init_default()
{
    init_int_list(&list);
    return 0;
}

int destroy()
{
    free_linkedlist(&list);
}

static CU_TestInfo testcase_create_and_destroy[] = {
    {"test_create",test_create},
    {"test_free",test_free},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    {"Test instanciation", init_default, NULL , NULL, NULL, testcase_create_and_destroy},
    CU_SUITE_INFO_NULL,
};

void add_linkedlist_tests(void) 
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for linkedlist - %s ", CU_get_error_msg());
        exit(1);
    }
}