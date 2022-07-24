#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define SIZE2 27
#define SUCCESS 1
#define FAILURE 0
typedef struct filename
{
    char f_name[SIZE];
    struct filename * f_link;
}filename_t;

typedef struct sub_node
{
    int w_count;
    char file_name[SIZE];
    struct sub_node * s_link;
}s_node;

typedef struct main_node
{
    int f_count;
    char word[SIZE];
    s_node * s_link;
    struct main_node * link;
}m_node;

//function prototypes of file validation
int file_validation(char * files[], int size1, filename_t ** head);
int insert_fileLL(filename_t ** head, char * file);
int check_content(FILE * fptr, char * file_n);
int check_file(FILE * fptr, char * file_n);

//function prototypes of create database
int create_database(filename_t ** head, m_node * heads[SIZE2]);
int get_index(char letter);
int read_file(FILE * fptr, m_node * heads[SIZE2], char * FileName);
int create_MainNode(m_node ** head1, char * content, char * FileName);
int create_SubNode(m_node ** head2, char * FileName);
int search_and_update(m_node ** head3, char * content, char * FileName);

//function prototypes of display database
void display_database(m_node * heads[SIZE2]);
void print_MainNode(m_node * head, int index);
void print_SubNode(s_node * head1);

//function prototype of search word
void search_word(char * word, m_node * heads[SIZE2]);

//function prototypes of save database
void save_database(char * NewFile, m_node * heads[SIZE2]);
void database_to_file(FILE * fptr, m_node * head, int index);
void get_SubNode_data(FILE * fptr, s_node * head1);

//function prototypes of update database
int update_database(char * src_file, m_node * heads[SIZE2]);
int read_and_create(char * line, m_node * heads[SIZE2]);
#endif
