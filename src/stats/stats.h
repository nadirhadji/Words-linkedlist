/**
 * @file stats.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STATS_H
#define STATS_H

#include "../file_manager/file_manager.h"
#include "../linkedlist/linkedlist.h"
#include "../extractor/extractor.h"

/**
 * @brief Given the input file object and le builed words_list
 * will calculate the required statatistics.
 * 
 * Those metrics are :
 * 
 * 1- Total number words including redundency
 * 2- Total number words excluding redundency
 * 3- Total number of letters (excluding words redundency)
 * 4- The number of lines in the input file
 * 4- The most frequent letter in the text
 * 
 * @param file Input file
 * @param words_list build words list ( by extractor )
 */
void   edit_stats_file(FILE* file, Linkedlist *words_list );

#endif