/*
Name: Syed Zeeshan Ulla
Date: 24/07/2022
Description: DS project - Inverted search
Input:
Output:
*/

#include "main.h"

int update_database(char * src_file, m_node * heads[SIZE2])
{
    FILE * fptr = fopen(src_file, "r");
    if(check_file(fptr, src_file) == FAILURE)
    {
	printf("Can't update database\n");
	return FAILURE;
    }

    if(check_content(fptr, src_file) == FAILURE)
    {
	printf("Can't update database\n");
	return FAILURE;
    }
    char * line = malloc(sizeof(char) * 3000);
    while(fscanf(fptr, "%[^\n] ", line) != EOF)
    {
	read_and_create(line, heads);
    }
    printf("Database is updated successfully!!\n");
    return SUCCESS;
}

int read_and_create(char * line, m_node * heads[SIZE2])
{
    char * index = strtok(line, ";");
    int index2 = atoi(&index[1]);
    char * word = strtok(NULL, ";");
    char * FileCount = strtok(NULL, ";");
    int FileCount2 = atoi(FileCount);
    char * FileName = strtok(NULL, ";");
    char * WordCount = strtok(NULL, ";");
    int WordCount2 = atoi(WordCount);
    // create_MainNode() function is written in database
    create_MainNode(&heads[index2], word, FileName);

    if(WordCount2 > 1)
    {
	heads[index2]->s_link->w_count = WordCount2;
    }

    if(FileCount2 > 1)
    {
	heads[index2]->f_count = FileCount2;
	s_node * temp = heads[index2]->s_link;
	for(int i = 1; i < FileCount2; i++)
	{
	    FileName = strtok(NULL, ";");
	    WordCount = strtok(NULL, ";");
	    WordCount2 = atoi(WordCount);
	    // create_SubNode() function is written in database
	    create_SubNode(&heads[index2], FileName);
	    temp = temp->s_link;
	    if(WordCount2 > 1)
	    {
		temp->w_count = WordCount2;
	    }
	}
    }
    return SUCCESS;
}
