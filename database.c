/*
Documentation
Name: Syed Zeeshan Ulla
Date: 24/07/22
Description: DS project - Inverted search
Input:
Output:
*/

/* NOTE: Don't uncomment the commented printf statements in this file. Uncomment it if you want to understand the 
   flow of the program or track the program in case of any error. */

#include "main.h"

int create_database(filename_t ** head, m_node * heads[SIZE2])
{
    filename_t * temp = *head;
    FILE * fptr;
    while(temp != NULL)
    {
	fptr = fopen(temp->f_name, "r");

	read_file(fptr, heads, temp->f_name);
	printf("SUCCESSFUL: Database created for %s\n", temp->f_name);
	temp = temp->f_link;
    }
    printf("Database Created Successfully for given file(s)!!\n");
    return SUCCESS;
}

int read_file(FILE * fptr, m_node * heads[SIZE2], char * FileName)
{
    char content[SIZE];
    int index;
    while(fscanf(fptr, "%s", content) != EOF )
    {
	//printf("%s\n", content);
	index = get_index(content[0]);
	if(heads[index] == NULL)
	{
	    //printf("Calling create_MainNode\n");
	    //printf("Before: %p\n", heads[index]);
	    create_MainNode(&heads[index], content, FileName);
	}
	else
	{
	    //printf("Calling search_and_update\n");
	    //printf("Before: %p\n", heads[index]);
	    search_and_update(&heads[index], content, FileName);
	}
    }
    return SUCCESS;
}

int get_index(char letter)
{
    if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
    {
	int index;
	if(letter >= 'A' && letter <= 'Z' )
	{
	    letter += 32;//converting Uppercase to Lowercase  
	}
	index = letter % 97;
	return index;
    }
    return 26;
}

int create_MainNode(m_node ** head1, char * content, char * FileName)
{
    //printf("After: %p\n", *head1);
    m_node * new = malloc(sizeof(m_node));
    if(new == NULL)
    {
	printf("Can't create new node in create_MainNode function\n");
	return FAILURE;
    }
    new->f_count = 1;
    strcpy(new->word, content);
    new->s_link = NULL;
    new->link = NULL;
    if(*head1 == NULL)
    {
	*head1 = new;
	//printf("calling create_SubNode for %s\n", FileName);
	//printf("Before: %p\n", head1);
	create_SubNode(head1, FileName);
	return SUCCESS;
    }
    else
    {
	m_node * temp = *head1;
	while(temp->link != NULL)
	{
	    temp = temp->link;
	}
	temp->link = new;
	//printf("calling create_SubNode for %s\n", FileName);
	//printf("Before: %p\n", temp);
	create_SubNode(&(temp->link), FileName);
	return SUCCESS;
    }
}

int create_SubNode(m_node ** head2, char * FileName)
{
    //printf("After: %p\n", *head2);
    s_node * new = malloc(sizeof(s_node));
    if(new == NULL)
    {
	printf("Can't create new node in create_SubNode function\n");
	return FAILURE;
    }
    new->w_count = 1;
    strcpy(new->file_name, FileName);
    new->s_link = NULL;
    if((*head2)->s_link == NULL)
    {
	(*head2)->s_link = new;
	return SUCCESS;
    }
    else
    {
	s_node * temp = (*head2)->s_link;
	while(temp->s_link != NULL)
	{
	    temp = temp->s_link;
	}
	temp->s_link = new;
	return SUCCESS;
    }
    return FAILURE;
}

int search_and_update(m_node ** head3, char * content, char * FileName)
{
    //printf("After: %p\n", *head3);
    m_node * temp = *head3;
    s_node * temp2 = (*head3)->s_link;
    while(temp != NULL)
    {
	if(strcmp(temp->word, content) == 0)
	{
	    while(temp2 != NULL)
	    {
		if(strcmp(temp2->file_name, FileName) == 0)
		{
		    //printf("Updating word_count in %s\n", FileName);
		    (temp2->w_count)++;
		    return SUCCESS;
		}
		if(temp2->s_link == NULL)
		{
		    (temp->f_count)++;
		    //printf("calling create_SubNode for %s\n", FileName);
		    //printf("Before: %p\n", temp);
		    create_SubNode(&temp, FileName);
		    return SUCCESS;
		}
		temp2 = temp2->s_link;
	    }
	}

	if(temp->link == NULL)
	{
	    //printf("calling create_MainNode for %s\n", FileName);
	    //printf("Before: %p\n", temp);
	    create_MainNode(&temp, content, FileName);
	    return SUCCESS;
	}

	temp = temp->link;
    }
    return FAILURE;
}
