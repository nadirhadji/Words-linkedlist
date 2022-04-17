/**
 * @file test_pop.c
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

void test_empty_pop()
{
    CU_ASSERT_TRUE( pop(list) == NULL );
}

void test_int_pop() 
{
    int five = *((int *) pop(list));
    CU_ASSERT_TRUE(five == 5);
    CU_ASSERT_TRUE(list->length == 4);
    
    int four = *( (int *) pop(list));
    CU_ASSERT_TRUE(four == 4);
    CU_ASSERT_TRUE(list->length == 3);
    
    int three = *( (int *) pop(list));
    CU_ASSERT_TRUE(three == 3);
    CU_ASSERT_TRUE(list->length == 2);
    
    int two = *( (int *) pop(list));
    CU_ASSERT_TRUE(two == 2);
    CU_ASSERT_TRUE(list->length == 1);
    
    int one = *( (int *) pop(list));
    CU_ASSERT_TRUE(one == 1);
    CU_ASSERT_TRUE(list->length == 0);
    
    void *n = pop(list);
    CU_ASSERT_TRUE(n == NULL);
}

void test_char_pop()
{
    char e = *((char *) pop(list));
    CU_ASSERT_TRUE(e == 'e');
    CU_ASSERT_TRUE(list->length == 4);
    
    char d = *( (char *) pop(list));
    CU_ASSERT_TRUE(d == 'd');
    CU_ASSERT_TRUE(list->length == 3);
    
    char c = *( (char *) pop(list));
    CU_ASSERT_TRUE(c == 'c');
    CU_ASSERT_TRUE(list->length == 2);
    
    char b = *( (char *) pop(list));
    CU_ASSERT_TRUE(b == 'b');
    CU_ASSERT_TRUE(list->length == 1);
    
    char a = *( (char *) pop(list));
    CU_ASSERT_TRUE(a == 'a');
    CU_ASSERT_TRUE(list->length == 0);
    
    void *n = pop(list);
    CU_ASSERT_TRUE(n == NULL);
}

void test_string_pop()
{
    char *strings[] = {"admin","bob","kim","joe","jan","rick"};

    char *rick = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(rick,"rick");
    CU_ASSERT_TRUE(list->length == 5);

    char *jan = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(jan,"jan");
    CU_ASSERT_TRUE(list->length == 4);

    char *joe = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(joe,"joe");
    CU_ASSERT_TRUE(list->length == 3);

    char *kim = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(kim,"kim");
    CU_ASSERT_TRUE(list->length == 2);

    char *bob = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(bob,"bob");
    CU_ASSERT_TRUE(list->length == 1);

    char *admin = (char *)(pop(list));
    CU_ASSERT_STRING_EQUAL(admin,"admin");
    CU_ASSERT_TRUE(list->length == 0);

    void *n = pop(list);
    CU_ASSERT_TRUE(n == NULL);
}

//Test configuration
init_pop()
{
    init_int_list(&list);
    return 0;
}

init_int_pop()
{
    init_full_int_list(&list);
    return 0;
}

init_char_pop()
{
    init_full_char_list(&list);
    return 0;
}

init_string_pop()
{
    init_full_string_list(&list);
    return 0;
}

destroy_pop()
{
    free_linkedlist(&list);
    return 0;
}

static CU_TestInfo testcases_pop_empty[] = {
    {"test pop in empty list",test_empty_pop},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_pop_int[] = {
    {"test pop in int list",test_int_pop},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_pop_char[] = {
    {"test pop in char list",test_char_pop},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_pop_string[] = {
    {"test pop in string list",test_string_pop},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites_pop[] = {
    {"Test empty pop",  init_pop,   destroy_pop, NULL, NULL, testcases_pop_empty},
    {"Test int pop",    init_int_pop,   destroy_pop, NULL, NULL, testcases_pop_int},
    {"Test char pop",   init_char_pop,     destroy_pop, NULL, NULL, testcases_pop_char},
    {"Test string pop", init_string_pop,     destroy_pop, NULL, NULL, testcases_pop_string},
    CU_SUITE_INFO_NULL,
};

void add_pop_tests(void) 
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites_pop) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for pop in linkedlist - %s ", CU_get_error_msg());
        exit(1);
    }
}
