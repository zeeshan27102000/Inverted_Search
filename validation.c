
#include "main.h"

int file_validation(char * files[], int size1, filename_t ** head)
{
    int status1, status2;
    FILE * fptr;
    for(int i = 1; i < size1; i++)
    {
	fptr = fopen(files[i], "r");
	status1 = check_file(fptr, files[i]);
	if(status1 == SUCCESS)
	{
	    status2 = check_content(fptr, files[i]);
	}
	else
	{
	    status2 = FAILURE;
	}
	if(status1 == SUCCESS && status2 == SUCCESS)
	{
	    if(insert_fileLL(head, files[i]))
	    {
		printf("SUCCESSFUL: %s is added to the list\n", files[i]);
	    }
	    else
	    {
		printf("FAILURE: %s is not added to list\n", files[i]);
	    }
	}
	else
	{
	    printf("FAILURE: %s is not added to list\n", files[i]);
	}	    
    }

    if(*head == NULL)
    {
	printf("File list is empty. Please pass existing and non-empty files\n");
	return FAILURE;
    }
    printf("File validation is Successful!\n");
    return SUCCESS;
}

int insert_fileLL(filename_t ** head, char * file)
{
    filename_t * new = malloc(sizeof(filename_t));
    if(new == NULL)
    {
	return FAILURE;
    }
    strcpy(new->f_name, file);
    new->f_link = NULL;
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }

    filename_t * temp = *head;
    while(temp != NULL)
    {
	if(strcmp(temp->f_name, file) == 0)
	{
	    printf("%s already present in list\nSo %s will not be added to file list again\n", file, file);
	    return FAILURE;
	}
	if(temp->f_link == NULL)
	{
	    temp->f_link = new;
	    return SUCCESS;
	}
	temp = temp->f_link;
    }
}

int check_file(FILE *fptr, char * file_n)
{
    if(fptr == NULL)
    {
	printf("%s doesn't exist in your directory\n", file_n);
	return FAILURE;
    }
    return SUCCESS;
    
}

int check_content(FILE *fptr, char * file_n)
{
    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
	printf("%s is empty file\n", file_n);
	return FAILURE;
    }
    return SUCCESS;
}
