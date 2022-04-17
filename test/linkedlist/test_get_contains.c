/**
 * @file test_get_contains.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "linkedlist_init.h"

static Linkedlist *list;

int int_equals(void* a,void* b) 
{
    int casted_a = *( (int *) a);
    int casted_b = *( (int *) b);
    int res = casted_a == casted_b ? 0 : 1;
    return res;
}

int char_equals(void* a,void* b) 
{
    char casted_a = *( (char *) a);
    char casted_b = *( (char *) b);
    int res = casted_a == casted_b ? 0 : 1;
    return res;
}

int str_equals(void* a,void* b)
{
    char *casted_a = (char *) a;
    char *casted_b = (char *) b;
    int res = strcmp(casted_a,casted_b) == 0 ? 0 : 1;
    return res;
}

void test_get_from_empty() 
{
    int val = 2;
    void* got = get(list,&val);
    CU_ASSERT_PTR_NULL(got);
}

void test_contains_from_empty()
{
    char val = 'f';
    CU_ASSERT_FALSE(contains(list,&val));
}

void test_found_int_get() 
{
    int val = 5;
    void* got = get(list,&val);
    int got_casted = got == NULL ? -1 : *( (int *)got);
    CU_ASSERT_TRUE(got_casted == val);
}

void test_not_found_int_get() 
{
    int val = 8;
    void* got = get(list,&val);
    CU_ASSERT_TRUE(got == NULL);
}

void test_found_char_get() 
{
    char val = 'a';
    void* got = get(list,&val);
    char got_casted = got == NULL ? 0 : *( (char *) got );
    CU_ASSERT_TRUE(got_casted == val);
}

void test_not_found_char_get() 
{
    char val = 'z';
    void* got = get(list,&val);
    char got_casted = got == NULL ? 0 : *( (char *)got);
    CU_ASSERT_TRUE(got_casted == 0);
}

void test_found_string_get() 
{
    const char *val = "admin";
    char *got = (char *)get(list,val);
    CU_ASSERT_STRING_EQUAL(val,got);
}

void test_not_found_string_get() 
{
    const char *val = "rooftop";
    void *got = get(list,val);
    CU_ASSERT_PTR_NULL(got);
}

void test_int_true_contains() 
{
    int val = 4;
    CU_ASSERT_TRUE(contains(list,&val));
}

void test_int_false_contains() 
{
    int val = 15;
    CU_ASSERT_FALSE(contains(list,&val));
}

void test_char_true_contains() 
{
    char val = 'b';
    CU_ASSERT_TRUE(contains(list,&val));
}

void test_char_false_contains() 
{
    char val = 'x';
    CU_ASSERT_FALSE(contains(list,&val));
}

void test_string_true_contains() 
{
    const char *val = "kim";
    CU_ASSERT_TRUE(contains(list,val));
}

void test_string_false_contains() 
{
    const char *val = "gotze";
    CU_ASSERT_FALSE(contains(list,val));
}

//Test configuration
init_get()
{
    init_int_list(&list);
    return 0;
}

init_int_get()
{
    init_full_int_list(&list);
    return 0;
}

init_char_get()
{
    init_full_char_list(&list);
    return 0;
}

init_string_get()
{
    init_full_string_list(&list);
    return 0;
}

destroy_get()
{
    free_linkedlist(&list);
    return 0;
}

static CU_TestInfo testcases_get_contains_empty[] = {
    {"test_get_from_empty",test_get_from_empty},
    {"test_contains_from_empty",test_contains_from_empty},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_get_contains_int[] = {
    {"test_found_int_get",test_found_int_get},
    {"test_not_found_int_get",test_not_found_int_get},
    {"test_int_false_contains",test_int_false_contains},
    {"test_int_true_contains",test_int_true_contains},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_get_contains_char[] = {    
    {"test_found_char_get",test_found_char_get},
    {"test_not_found_char_get",test_not_found_char_get},
    {"test_char_false_contains",test_char_false_contains},
    {"test_char_true_contains",test_char_true_contains},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_get_contains_string[] = {
    {"test_found_string_get",test_found_string_get},
    {"test_not_found_string_get",test_not_found_string_get},
    {"test_string_false_contains",test_string_false_contains},
    {"test_string_true_contains",test_string_true_contains},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    {"Test contains and get int in linkedlist", 
    init_int_get, destroy_get, NULL, NULL, testcases_get_contains_int},
    {"Test contains and get char in linkedlist", 
    init_char_get, destroy_get, NULL, NULL, testcases_get_contains_char},
    {"Test contains and get string in linkedlist", 
    init_string_get, destroy_get, NULL, NULL, testcases_get_contains_string},
    {"Test contains and get in empty linkedlist", 
    init_get, destroy_get, NULL, NULL, testcases_get_contains_empty},
    CU_SUITE_INFO_NULL,
};

void add_get_contains_tests(void) {
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for contains in linkedlist - %s ", CU_get_error_msg());
        exit(1);
    }
}
