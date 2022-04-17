/**
 * @file init.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "linkedlist_init.h"

int int_compare( void *a,  void *b)
{
    if ( *(int *) a < *(int *) b )
        return -1;
    if ( *(int *) a > *(int *) b ) 
        return 1;
    return 0;
}

int char_compare( void *a,  void *b )
{
    if ( *(char *) a < *(char *) b )
        return -1;
    if ( *(char *) a > *(char *) b ) 
        return 1;
    return 0;
}

int str_compare(void *a,  void *b)
{
    int val = strcmp( (char *) a, (char *) b );
    if ( val < 0 )
        return -1;
    if ( val > 0 )
        return 1;
    return 0;
}

void free_data()
{
    return;
}

void str_print(void *str)
{
    printf("%s\n",(char *)str);   
}

void int_print(void *num)
{
   printf("%d\n", *(int *)num);
}

void char_print(void *num)
{
   printf("%c\n", *(char *)num);
}

int init_int_list(Linkedlist **list)
{
    *list = create_linkedlist(int_compare,int_print,free_data);
    return 0;
}

int init_char_list(Linkedlist **list)
{
    *list = create_linkedlist(char_compare,char_print,free_data);
    return 0;
}

int init_string_list(Linkedlist **list)
{   
    *list = create_linkedlist(str_compare,str_print,free_data);
    return 0;
}

int init_full_string_list(Linkedlist **list) {
    init_string_list(list);
    char *strings[] = {"admin","bob","kim","joe","jan","rick"};
    for(int i = 0 ; i < 6; ++i) 
        push((*list),strings[i]);
    return 0;
}

int init_full_int_list(Linkedlist **list){
    init_int_list(list);
    int integers[] = {1,2,3,4,5};
    for(int i = 0 ; i < (sizeof(integers)/sizeof(int)); ++i) 
        push((*list),&integers[i]);
    
    return 0;
}

int init_full_char_list(Linkedlist **list) {
    init_char_list(list);
    char array[] = {'a','b','c','d','e'};
    for(int i = 0 ; i < (sizeof(array)/sizeof(char)); ++i) 
        push((*list),&array[i]);
    return 0;
}

int cleanup(Linkedlist **list) {
    //printf("I'm about to free %d\n",list);
    free_linkedlist(*list);
    (*list)->head = NULL;
    (*list)->length = 0;
    list = NULL;
    free((*list));
    return 0;
}