/**
 * @file test_file_open_close.c
 * @author Nadir Hadji - HADN08069703
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "CUnit/Basic.h"
#include "../../src/file_manager/file_manager.h"

#define EMPTY_FILE_PATH "./test/file_manager/test_files/empty_input_file.txt"
#define VALID_INPUT_TEXT "./test/file_manager/test_files/valid_inupt_file.txt"
#define ONE_LINE_FILE "./test/file_manager/test_files/one_line_file.txt"

static FILE* file = NULL;

void test_opening_of_existing_file() 
{
    file = open_file(VALID_INPUT_TEXT);
    CU_ASSERT_PTR_NOT_NULL(file);
}

void test_opening_non_existent_file() 
{
    FILE *file = open_file("no-here.txt");
    CU_ASSERT_PTR_NULL(file);
}

void test_close_of_opened_file() 
{
    CU_ASSERT_TRUE(close_file(file) == 0);
}

void test_next_word() 
{
    char buffer[81];

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"JE");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"SUIS");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"UN");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"FICHIER");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"TEST");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"VALIDE");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"I");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"LOVE");
    memset(buffer, 0, sizeof(buffer));

    next_word(file,buffer);
    CU_ASSERT_STRING_EQUAL(buffer,"C");
    memset(buffer, 0, sizeof(buffer));
}

void test_next_word_at_end() 
{
    char buffer[81];
    CU_ASSERT_EQUAL(next_word(file,buffer),EOF);
}

void test_has_next_true() 
{
    char buffer[81];
    for (int i = 0 ; i < 9 ; ++i) {
        CU_ASSERT_TRUE(has_next(file));
        next_word(file,buffer);
    }
}

void test_has_next_false() 
{
    char buffer[81];
    CU_ASSERT_FALSE(has_next(file));
}

void test_number_line_empty() 
{
    FILE* empty = open_file(EMPTY_FILE_PATH);
    CU_ASSERT_TRUE(get_number_lines(empty) == 0);
}

void test_multi_number_lines() 
{
    CU_ASSERT_TRUE(get_number_lines(file) == 3);
}

void test_one_number_line()
{
    file = open_file(ONE_LINE_FILE);
    CU_ASSERT_TRUE(get_number_lines(file) == 1);
}

void test_pointer_position_after_number_line() 
{
    char buffer[81];
    next_word(file,buffer);
    long position_before = ftell(file);
    int nb_lines = get_number_lines(file);
    long position_after = ftell(file);
    CU_ASSERT_EQUAL(position_before,position_after);
}

//Test configuration
int init_file() 
{
    file = open_file(VALID_INPUT_TEXT);
    return 0;
}

int cleanup_file() 
{
    file != NULL ? close_file(file) : 0 ;
    return 0;
}

static CU_TestInfo testcases_open_file[] = 
{
    {"test_opening_non_existent_file",test_opening_non_existent_file},
    {"test_opening_of_existing_file",test_opening_of_existing_file},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_close_file[] = 
{
    {"test_close_of_opened_file",test_close_of_opened_file},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_next_word[] = 
{
    {"test_next_word",test_next_word},
    {"test_next_word_at_end",test_next_word_at_end},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_has_next[] = 
{
    {"test_has_next_true",test_has_next_true},
    {"test_has_next_false",test_has_next_false},
    CU_TEST_INFO_NULL,
};

static CU_TestInfo testcases_number_lines[] = 
{
    {"test_number_line_empty",test_number_line_empty},
    {"test_legit_number_lines",test_multi_number_lines},
    {"test_one_number_line",test_one_number_line},
    {"test_pointer_position_after_number_line",test_pointer_position_after_number_line},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = 
{
    {"testcases_open_file", NULL, NULL, NULL, NULL, testcases_open_file},
    {"testcases_close_file", NULL, NULL, init_file, NULL, testcases_close_file},
    {"testcases_next_word",init_file,cleanup_file,NULL,NULL,testcases_next_word},
    {"testcases_has_next",init_file,cleanup_file,NULL,NULL,testcases_has_next},
    {"testcases_number_lines", NULL, NULL, init_file, cleanup_file, testcases_number_lines},
    CU_SUITE_INFO_NULL,
};

void add_file_manager_tests(void) 
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for file open and close - %s ", CU_get_error_msg());
        exit(1);
    }
}
