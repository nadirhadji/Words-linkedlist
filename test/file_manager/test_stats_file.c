/**
 * @file test_stats_file.c
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

static FILE* file = NULL;

//Test configuration
int init_test_stats(){
    return 0;
}

int cleanup_test_stats() {
    return 0;
}

static CU_TestInfo testcases_write_stats_file[] = {
    {"",},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    {"",  NULL, NULL , NULL, NULL, testcases_write_stats_file},
    CU_SUITE_INFO_NULL,
};

void add_statistics_tests(void) 
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());
    if( CU_register_suites(suites) != CUE_SUCCESS) 
    {
        fprintf(stderr, "Suites registration failed for file open and close - %s ", CU_get_error_msg());
        exit(1);
    }
}
