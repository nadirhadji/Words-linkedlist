/**
 * @file linkedlist.c
 * @author Nadir Hadji - HADN0869703
 * @brief Implementation if a generic linkedlist.
 * 
 * Before using it, make sure you are aware that the create methode
 * need in it arguments a compare , print and free function matching
 * with the type of data you want to store.
 * 
 * Every methode is protected by an assertion if those methods are not 
 * initialised.
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "assert.h"
#include "linkedlist.h"

//Private
Node*   create_node(void* new_value) 
{
    Node *new_node = (Node *) malloc( sizeof( Node ) );
    new_node->value = new_value;
    new_node->next = NULL;
    return new_node;
}

//Public

//OK
Linkedlist*   create_linkedlist( int (*cmpData)( void *,void *), 
                                    void (*printData)( void *), 
                                    void (*freeData)( void *) ) 
{
    Linkedlist *llist = malloc(sizeof(Linkedlist));
    if (llist == NULL) return NULL;
    llist->head =   NULL;
    llist->length = 0;
    llist->compare_data =   cmpData;
    llist->print_data = printData;
    llist->free_data =  freeData;
    return llist;
}

//OK
void    free_linkedlist(Linkedlist *linkedlist) 
{
    assert( linkedlist != NULL);
    assert( linkedlist->free_data != NULL );

    if(linkedlist == NULL) return;
    Node *current;
    
    while ((current = linkedlist->head) != NULL) 
    {
		linkedlist->head = linkedlist->head->next;
		if(current->value != NULL)
        {
            linkedlist->free_data(current->value);
        }
		free (current);
        current->value = NULL;
        current->next = NULL;
        current = NULL;
	}
    free(linkedlist);
}

//OK - tested
int     push_in_order(Linkedlist *linkedlist, void *value) 
{
    assert( linkedlist != NULL );
    assert( linkedlist->compare_data != NULL);
    Node *temp = linkedlist->head;
    Node *prev = NULL;

    //Empty list
    if (temp == NULL) 
    {
        push(linkedlist,value);
        return 1;
    }

    bool is_value_greater = false;
    //Looking for the node before who to insert
    while ( temp != NULL && temp->value != NULL && !is_value_greater ) 
    {
        int res = linkedlist->compare_data(temp->value , value);

        if ( res == 0 )
            return 1;

        if ( res < 0 ) 
        {
            prev = temp;
            temp = temp->next;
            is_value_greater = false;
        } 
        else
            is_value_greater = true;
    }

    //case of insertion at the first position before head
    if (prev == NULL) 
        push(linkedlist,value);

    //case of insertion between two cells
    else
    {
        Node * new_node = create_node(value);
        prev->next = new_node;
        new_node->next = temp;
        ++linkedlist->length;
    }

    return 1;
}

//OK-tested
void    push( Linkedlist *linkedlist, void *new_value) 
{
    assert( linkedlist != NULL );
    assert( linkedlist->compare_data != NULL);
    Node *new_node = create_node(new_value);
    if (linkedlist->head == NULL)
        linkedlist->head = new_node;
    else
        new_node->next = linkedlist->head;
    linkedlist->head = new_node;
    ++linkedlist->length;
}

//OK-tested
void*   pop(Linkedlist *linkedlist) 
{
    assert( linkedlist != NULL );
    assert( linkedlist->free_data != NULL );

    if (linkedlist->head == NULL)
        return NULL;
    
    Node *temp = linkedlist->head;
    Node *next = temp->next;
    void *value = NULL;
    if ( temp != NULL)
    {
        value = temp->value;
        linkedlist->free_data(linkedlist->head->value);
        free(linkedlist->head);
        linkedlist->head = next;
        --linkedlist->length;
    }
    return value;
}

//OK
int     print_list(Linkedlist *linkedlist) 
{
    assert(linkedlist != NULL);
    assert(linkedlist->print_data != NULL);
    Node *temp = linkedlist->head;

    if (linkedlist->head == NULL && linkedlist->length == 0) 
    {
        printf("The linkedlist is empty");
        return 1;
    }
    while( temp != NULL ) 
    {
        linkedlist->print_data(temp->value);
        //putchar('\n');
        temp = temp->next;
    }
    return 1;
}

//OK-tested
bool    contains(Linkedlist *linkedlist, void* value ) 
{
    assert(linkedlist != NULL);
    assert(linkedlist->compare_data != NULL);
    return ( get(linkedlist,value) != NULL);
}

//OK-tested
void*   get(Linkedlist *linkedlist, void* value ) {
    assert(linkedlist != NULL);
    assert(linkedlist->compare_data != NULL);
    Node *temp = linkedlist->head;
    
    while(temp != NULL) 
    {
        if ( linkedlist->compare_data(value,temp->value) == 0)
            return temp->value;
        temp = temp->next;
    }
    return NULL;
}

void str_print(void *str)
{
    printf("%s\n",(char *)str);   
}

void num_print(void *num)
{
   printf("%d\n", *(int *)num);
}

void char_print(void *num)
{
   printf("%c\n", *(char *)num);
}
