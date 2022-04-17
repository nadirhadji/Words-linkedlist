/**
 * @file file_manager.c
 * @author Nadir Hadji - HADN08069703
 * @brief Implementation of the file manager
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "file_manager.h"

#define STATS_FILE_NAME "statistique.txt"
#define STATS_HEADER    "\t\t\t\t - STATISTIQUE -\n\n"
#define LABAL_STAT_1    "le nombre de mots sans doublons = "
#define LABEL_STAT_2    "le nombre de mots avec doublons = "
#define LABEL_STAT_3    "le nombre de lignes dans le fichier d'entrée = "
#define LABEL_STAT_4    "le nombre de lettres dans la liste de mots (sans considérer les doublons) = "
#define LABEL_STAT_5    "la lettre la plus fréquente (sans considérer les doublons) = "

#define log_error_file_open() \
    fprintf(stderr,"Erreur : Echec de l'ouverture du fichier.\n"); \

#define log_error_file_close() \
    fprintf(stderr,"Erreur : Echec de la fermeture du fichier. \n"); \

/**
 * @brief Open a file in the specified mode.
 * only read and write and handeled.
 * 
 * @param file_name 
 * @param mode 
 * @return FILE* file in specified mode
 */
FILE*   open_file_with_mode(const char *file_name, const char *mode)
{
    FILE *file = fopen(file_name,mode);
    if ( file == NULL) 
    {
        #ifndef TEST
        log_error_file_open();
        exit(EXIT_FAILURE);
        #endif 
    }
    return file;
}

/**
 * @brief Generic function to append label and associated value in a file
 * 
 * @param filename 
 * @param label label associated with the int value
 * @param value int value associated with the label
 */
void    generic_int_append(const char *filename, const char *label, int value )
{
    FILE *file = open_file_with_mode(filename,"a");
    char buffer[10];
    sprintf(buffer,"%d",value);
    fputs(label,file);
    fputs(buffer,file);
    fputc('\n',file);
    close_file(file);
}

/**
 * @brief Generic function to append a char associated with a label
 * 
 * @param filename 
 * @param label label associated with the char value
 * @param value char value associated with the label
 */
void    generic_char_append(const char *filename, const char *label, char value)
{
    FILE *file = open_file_with_mode(filename,"a");
    fputs(label,file);
    fputc(value,file);
    fputc('\n',file);
    close_file(file);
}

FILE*   open_file(const char *file_name) 
{
    return open_file_with_mode(file_name,"r");
}

int     close_file(FILE *file) 
{
    int val = file == NULL ? -1 : fclose(file);
    #ifndef TEST
    if ( val == -1 || val > 0 ) 
        log_error_file_close();
    #endif 
    return val; 
}

int     next_word(FILE* file , char* buffer) 
{
    int res = fscanf(file,"%s",buffer);
    if (strlen(buffer) == 0 )
        return -1;
    return res;
}

bool    has_next(FILE* file) 
{
    bool state = feof(file) == 0 ? true : false;
    return state;
}

int    count(FILE* file) 
{
    int nb_lines = 0, nb_letter = 0;
    for ( char c = getc(file); c != EOF; c = getc(file) ) 
    {
        if ( c == '\n' ) {
            ++nb_lines;
            nb_letter = 0;
        }
        else ++nb_letter;
    }
    if ( nb_letter > 0 ) ++nb_lines;
    return nb_lines;
}

int     get_number_lines(FILE* file)
{
    long initial_pointer_position = ftell(file);
    rewind(file);   
    int nb_lines = count(file);
    fseek(file, initial_pointer_position, SEEK_SET);
    return nb_lines;
}

void   create_stats_file()
{
    FILE * file;
    file = fopen(STATS_FILE_NAME, "w");
    if(file == NULL)
    {
        #ifndef TEST
        printf("Unable to create file statistics.\n");
        exit(EXIT_FAILURE);
        #endif 
    }
    fputs(STATS_HEADER,file);
    fclose(file);
}

void    append_global_words_count(int count) 
{
    generic_int_append(STATS_FILE_NAME,LABAL_STAT_1,count);
}

void    append_unique_words_count(int count) 
{
    generic_int_append(STATS_FILE_NAME,LABEL_STAT_2,count);
}

void    append_lines_count(int count) 
{
    generic_int_append(STATS_FILE_NAME,LABEL_STAT_3,count);
}

void    apprend_letters_count(int count) 
{
    generic_int_append(STATS_FILE_NAME,LABEL_STAT_4,count);
}

void    append_most_frequent_letter(char letter) 
{
    generic_char_append(STATS_FILE_NAME,LABEL_STAT_5,letter);
}
