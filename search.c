/*
Name: Syed Zeeshan Ulla
Date: 27/07/2022
Description: DS project - Inverted search
Input:
Output:
*/

#include "main.h"

void search_word(char * word, m_node * heads[SIZE2])
{
    int index = get_index(word[0]); // function get_index() is written in database.c file
    if(heads[index] == NULL)
    {
	printf("word '%s' is not present in database\n", word);
	return;
    }
    printf("Word '%s' is present in %d file(s)\n", word, heads[index]->f_count);
    s_node * temp = heads[index]->s_link;
    while(temp != NULL)
    {
	printf("In file: %s %d time(s)\n",temp->file_name, temp->w_count);
	temp = temp->s_link;
    }
    return;
}
