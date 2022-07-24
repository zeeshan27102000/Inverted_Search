/*
Documentation
Name: Syed Zeeshan Ulla
Date: 24/07/22
Description: DS project - Inverted search
Input:
Output:
*/

#include "main.h"

void display_database(m_node * heads[SIZE2])
{
    printf("[index]		[word]		filecount	:	Filename		wordcount\n");
    for(int i = 0; i < SIZE2; i++ )
    {
	print_MainNode(heads[i], i);
    }
    return;
}

void print_MainNode(m_node * head, int index)
{
    if(head != NULL)
    {
	m_node * temp = head;
	while(temp != NULL)
	{
	    printf("[%d]   		[%s]		%d file(s)	:", index, temp->word, temp->f_count);
	    print_SubNode(temp->s_link);
	    temp = temp->link;
	}
	return;
    }
    return;
}

void print_SubNode(s_node * head1)
{
    s_node * temp = head1;
    while(temp != NULL)
    {
	printf("	file: %s		%d time(s)", temp->file_name, temp->w_count);
	temp = temp->s_link;
    }
    printf("\n");
    return;
}
