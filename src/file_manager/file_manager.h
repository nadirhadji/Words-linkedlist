/**
 * @file reader.h
 * @author Nadir Hadji - HADN08069703
 * @brief Module to handle all the interactions to be made with
 * the input and the output file if needed.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _FILE_MANAGER__H_
#define _FILE_MANAGER__H_

#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Open the file in read mode and return it if he exist. Null otherwise.
 * 
 * @param file_name Name or path to the file to open.
 * @return FILE* poiter to the file or null if an error occued. 
 */
FILE*   open_file(const char *file_name);

/**
 * @brief Close the file given in parameter
 * 
 * @param file *FILE type object
 * @return int 0 if closed, -1 if not
 */
int     close_file(FILE *file);

/**
 * @brief Set the next word in the const char * in argument
 * 
 * @return int 0 if failure >0 if not
 */
int     next_word(FILE*, char*);

/**
 * @brief Check if the position of the pointer is not aht EOF
 * 
 * @return true end of file
 * @return false not end of file
 */
bool    has_next(FILE*);

/**
 * @brief Get the number lines object
 * 
 * @param file 
 * @return int total
 */
int     get_number_lines(FILE* file);

/**
 * @brief Create an empty statictics file object
 * 
 * @return FILE* file object
 */
void   create_stats_file();

/**
 * @brief Append a formated sentence to the stats file 
 * about the total number of words in the input file.
 * 
 * @param count total number of words in the input file.
 */
void    append_global_words_count(int count);

/**
 * @brief Append a formated sentence to the stats file 
 * about the total number of words in the words list.
 * 
 * @param count total number of words in the words list.
 */
void    append_unique_words_count(int count);

/**
 * @brief Append a formated sentence to the stats file 
 * about the total number of lines in the input file.
 * 
 * @param count total number of lines in the input file.
 */
void    append_lines_count(int count);

/**
 * @brief Append a formated sentence to the stats file 
 * about the total number of letters in the words list.
 * 
 * @param count total number of letters in the words list.
 */
void    apprend_letters_count(int count);

/**
 * @brief Append a formated sentence to the stats file.
 * about the most frequent line in the words list.
 * 
 * @param letter the most frequent line in the words list
 */
void    append_most_frequent_letter(char letter);

#endif