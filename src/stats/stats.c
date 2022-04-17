/**
 * @file stats.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stats.h"


/**
 * @brief get the total number of words in the list
 * considering redundancy
 * 
 * @param list pointer to linkedist
 */
int    get_total_number_words ( Linkedlist * list )
{
    int count = 0;
    struct Node *temp = list->head;

    while( temp != NULL )
    {
        count += ( (Word *) temp->value )->count;
        temp = temp->next;
    }
    return count;
}

/**
 * @brief get the number of words in the list
 * without considering redundancy
 * 
 * @param list pointer to linkedist
 */
int    get_number_words ( Linkedlist * list )
{
    int count = 0;
    Node *temp = list->head;

    while( temp != NULL )
    {
        ++count;
        temp = temp->next;
    }
    return count;
}

/**
 * @brief get a the number of letters int the words list
 * 
 * @param list pointer to linkedist
 */
int    get_number_of_letters ( Linkedlist * list )
{
    int count = 0;
    Node *temp = list->head;

    while( temp != NULL )
    {
        int nb_letters = strlen(( (Word *) temp->value)->one_word );
        count += nb_letters;
        temp = temp->next;
    }
    return count;
}

/**
 * @brief get most frequent letter in the list
 * 
 * @param letter pointer to linkedlist
 */
char   get_most_frequent_letter ( Linkedlist *words_list )
{
    Linkedlist *letters_list = build_letters_list(words_list);
    Node *temp = letters_list->head;
    int     max = 0;
    char    most_frequent = 0;

    while ( temp != NULL )
    {
        Letter *ptr_letter = (Letter *) temp->value;
        if (ptr_letter->count > max)
        {
            max = ptr_letter->count;
            most_frequent = ptr_letter->one_letter;
        }
        temp = temp->next;
    }
    free_linkedlist(letters_list);
    return most_frequent;
}

void   edit_stats_file(FILE* file, Linkedlist *words_list )
{
    create_stats_file();
    append_unique_words_count( get_number_words(words_list) );
    append_global_words_count( get_total_number_words(words_list) );
    append_lines_count( get_number_lines(file) );
    apprend_letters_count( get_number_of_letters(words_list) );
    append_most_frequent_letter( get_most_frequent_letter(words_list) );
}