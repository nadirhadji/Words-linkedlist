/**
 * @file sorter.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "src/stats/stats.h"
#include "src/extractor/extractor.h"
#include "src/file_manager/file_manager.h"
#include "src/linkedlist/linkedlist.h"

#define MAX_LENGTH 81

#define TEST_FILE "/home/ledag/source/inf3135/inf3135-hiv2022-tp3/test.txt"

int main(int argc, char const *argv[])
{
    char filename[] = TEST_FILE;
    FILE* file = open_file(filename);
    Linkedlist* list = build_words_list(file);
    edit_stats_file(file,list);
    close_file(file);
    free_linkedlist(list);
    return 0;
}