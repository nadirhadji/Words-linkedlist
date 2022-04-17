/**
 * @file test_manager.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "CUnit/Basic.h"

int main(int argc, char const *argv[])
{
    if(CUE_SUCCESS != CU_initialize_registry())
    {
        fprintf(stderr, " Initialization of Test Registry failed. ");
        exit(1);
    }
    else
    {
        /* Adding all the tests suites*/
        add_linkedlist_tests();
        add_push_tests();
        add_pop_tests();
        add_get_contains_tests();
        add_file_manager_tests();
    
        /* Run all tests using the CUnit Basic interface */
        CU_basic_set_mode(CU_BRM_VERBOSE);
        printf("\nTests completed with return value %d.\n", CU_basic_run_tests());
        CU_cleanup_registry();
    }
    return 0;
}