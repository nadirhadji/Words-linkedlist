/**
 * @file linkedlist.c
 * @author Nadir Hadji - HADN0869703
 * @brief LinkedList header
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 */
#ifndef _LINKEDLIST__H_
#define _LINKEDLIST__H_
#include "stdbool.h"

typedef struct Node {
    void *value;
    struct Node *next;
}Node;

typedef struct Linkedlist {
    int     length;
    Node    *head;
    int     (*compare_data)( void *, void *);
    void    (*print_data)( void *);
    void    (*free_data)( void *);
}Linkedlist;

/**
 * @brief Create a linkedlist object
 * 
 * @return Linkedlist* 
 */
Linkedlist*   create_linkedlist( int (*cmpData)( void *,void *), 
                                void (*printData)( void *), 
                                void (*freeData)( void *) );

/**
 * @brief Free the memory token by linkedlist
 * 
 * @param linkedlist 
 */
void        free_linkedlist(Linkedlist *linkedlist);

/**
 * @brief Add an element to a sorted linkedlist 
 * 
 * @param value value to be added
 * @param linkedlist the list 
 * @return int 0 or 1
 */
int         push_in_order(Linkedlist *linkedlist, void *value);

/**
 * @brief Add element before the first node of linkedlist
 * 
 * @param value 
 * @param linkedlist 
 */
void        push( Linkedlist *linkedlist, void *value);

/**
 * @brief Retreive and remoce the first element of the linkedlist
 * 
 * @param linkedlist 
 */
void*       pop(Linkedlist *linkedlist);

/**
 * @brief For debuf purpose, print value of each node in the list
 * 
 * @param linkedlist the list to be displayed
 * @param print the print methode that should cast ( void * -> type )
 * @return int 1 when ok, 0 when error.
 */
int         print_list(Linkedlist *linkedlist);

/**
 * @brief Check if the passed value is in the list
 * 
 * @param linkedlist the list to be checked
 * @param value the value to look for
 * @param equals the custom equals methode for value
 * @return void* true or false
 */
bool        contains(Linkedlist *linkedlist, void* value);

/**
 * @brief Retreive the element at the index position
 * 
 * @param linkedlist the linkedlist
 * @param index position of element 
 * @return void* the element or NULL
 */
void*       get(Linkedlist *linkedlist, void* value);

//Private
Node*       create_node(void* new_value);

//Private
void str_print(void *str);

#endif