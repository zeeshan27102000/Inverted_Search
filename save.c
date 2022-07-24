/*
Name: Syed Zeeshan Ulla
Date: 24/07/2022
Description: DS project - Inverted search
Input:
Output:
*/

#include "main.h"

void save_database(char * NewFile, m_node * heads[SIZE2])
{
    FILE * fptr = fopen(NewFile, "w");
    for(int i = 0; i < SIZE2; i++ )
    {
	if(heads[i] != NULL)
	{
	    database_to_file(fptr, heads[i], i);
	}
    }
    printf("Database is saved in %s file\n", NewFile);
    return;
}

void database_to_file(FILE * fptr, m_node * head, int index)
{
    while(head != NULL)
    {
	fprintf(fptr, "#%d;%s;%d;", index, head->word, head->f_count);
	get_SubNode_data(fptr, head->s_link);
	head = head->link;
    }
    return;
}

void get_SubNode_data(FILE * fptr, s_node * head1)
{
    while(head1 != NULL)
    {
	fprintf(fptr, "%s;%d;", head1->file_name, head1->w_count);
	head1 = head1->s_link;
    }
    fprintf(fptr, "#\n");
    return;
}
