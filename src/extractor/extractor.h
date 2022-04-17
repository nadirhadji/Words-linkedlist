/**
 * @file sorter.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _EXTRACTOR_H
#define _EXTRACTOR_H

#include <assert.h>
#include "../file_manager/file_manager.h"
#include "../linkedlist/linkedlist.h"

typedef struct {
    const char *one_word;
    unsigned int count;
}Word;

typedef struct {
    char one_letter;
    unsigned int count;
}Letter;

/**
 * @brief Will build a linkedlist of struct Word without redondance
 * 
 * The struct Word contain a pointer the the word on the heap and the 
 * number of occurence of the word in the input file.
 * 
 * @param filename name of the input file
 * @return Linkedlist* linkedlist of words in file with number of occurence
 */
Linkedlist* build_words_list(FILE* file);

/**
 * @brief Get the letters list object
 * 
 * @param words 
 * @return Linkedlist* 
 */
Linkedlist* build_letters_list( Linkedlist *words );

#endif