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
#include "extractor.h"

#define MAX_LENGTH 81

Letter*         new_letter(char letter)
{
    Letter *ptr_letter = (Letter *) malloc( sizeof( Letter ) );
    ptr_letter->one_letter = letter;
    ptr_letter->count = 1;
    return ptr_letter;
}

void            free_letter(void *ptr_letter)
{
    Letter *letter = (Letter *) ptr_letter;
    free( letter );
    letter->count = 0;
    letter->one_letter = 0;
}

void            print_letter(void *void_letter)
{
    Letter *ptr_letter = (Letter *) void_letter;
    printf("%d times the letter %c\n",ptr_letter->count,ptr_letter->one_letter);
}

int             compare_letters( void *a, void *b)
{
    Letter *temp_a = (Letter *) a;
    Letter *temp_b = (Letter *) b;
    int cmp_val = ( temp_b->one_letter - temp_a->one_letter);
    
    if ( cmp_val < 0 )
        return -1;
    if ( cmp_val > 0 )
        return 1;
    ++temp_a->count;
    return 0;
}

/**
 * @brief Create a word struct on the heap
 * 
 * @param str_word string of the word
 * @return Word* pointer to Word on heap
 */
Word*           new_word(char* str_word)
{
    Word *word;
    int width = strlen(str_word) + 1;
    word = malloc( sizeof(Word) );
    word->one_word = malloc(sizeof(char) * width );
    memcpy( (char *) word->one_word, str_word, width); 
    word->count = 1;
    return word;
}

/**
 * @brief Free the memory tooked by the word on the heap
 * 
 * In order to create a custom free method on a generic linkedlist
 * This function will be an argument for the initialisation of 
 * the Words linkedlist.
 * 
 * @param ptr_word pointer to the struct Word
 */
void            free_word(void *ptr_word)
{
    Word *word = (Word *) ptr_word;
    free( (char *) word->one_word);
    free(word);
}

/**
 * @brief Print a word from a void pointer on the heap
 * 
 * In order to create a custom priint method on a generic linkedlist
 * This function will be an argument for the initialisation of 
 * the Words linkedlist.
 * 
 * @param ptr_word pointer to the struct Word
 */
void            print_word(void *ptr_word) 
{
    Word *word = (Word *) ptr_word;
    char *acutal_word = (char *) word->one_word;
    printf("%d times words : %s \n", word->count, acutal_word);
}

/**
 * @brief Compare two words object from a void pointer.
 * 
 * In order to create a custom compare method on a generic linkedlist
 * This function will be an argument for the initialisation of 
 * the Words linkedlist. 
 * 
 * It will cast and compare the two word structs.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int             compare_words(void *a, void *b)
{
    Word *temp_a = (Word *) a;
    Word *temp_b = (Word *) b;
    int strcmp_val = strcmp(temp_a->one_word, temp_b->one_word);
    if ( strcmp_val < 0 )
        return -1;
    if ( strcmp_val > 0 )
        return 1;
    ++temp_a->count;
    return 0;
}

/**
 * @brief Read each word on the file, create a Word struct 
 * and append it to the linkedlist.
 * 
 * @param list linkedlist of words
 * @param file input file
 * @return int > 1 if ok 0 if bug.
 */
int             extract_words(Linkedlist* list, FILE* file) 
{
    int res = 0;
    while ( has_next(file) ) 
    {
        char buffer[MAX_LENGTH];
        res = next_word(file,buffer);
        if (res > 0 )  
        {
            Word buff = {buffer,1};
            Word *c_word = get(list,&buff);
            if ( c_word == NULL && buffer != NULL )
                push_in_order(list,new_word(buffer)); 
            else
                ++c_word->count;
        }        
    }
    return res;
}

Linkedlist*      init_words_list()
{
    Linkedlist* list = create_linkedlist(compare_words,
                                            print_word,
                                            free_word);
    return list;
}

Linkedlist*      init_letters_list()
{
    Linkedlist *list = create_linkedlist( compare_letters,
                                            print_letter,
                                            free_letter );
    return list;
}

Linkedlist*      build_words_list(FILE* file)
{
    assert(file != NULL);
    Linkedlist* list = init_words_list();
    extract_words(list,file);
    print_list(list);
    return list;
}

Linkedlist*     build_letters_list(Linkedlist *words_list )
{
    Linkedlist* letters_list = init_letters_list();
    assert(words_list != NULL);
    assert(letters_list != NULL);
    Node *temp = words_list->head;

    while(temp != NULL)
    {
        Word * word = (Word *) temp->value;
        char * buff = (char *) word->one_word;
        while( *buff != 0 ) 
        {
            Letter buffer = {*buff,1};
            Letter *c_letter = get(letters_list,&buffer);
            if ( c_letter == NULL && *buff != 0 )
                push_in_order(letters_list,new_letter(*buff)); 
            else
                ++c_letter->count;
            ++buff;
        }
        temp = temp->next;
    }
    return letters_list;
} 