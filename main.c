/*
Name: Syed Zeeshan Ulla
Date: 24/07/2022
Description: DS project - Inverted Search
Input:
Output:
*/

#include "main.h"

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
	filename_t * head = NULL; // head of filenames list
	file_validation(argv, argc, &head);
	//array of pointers which will contain addresses of all lists of all alphabets
	m_node * heads[SIZE2] = {NULL};
	char option = 'y', word[SIZE], backup_file[SIZE], src_file[SIZE];
	int choice, flag = 0;
	while(option == 'y' || option == 'Y')
	{
	    printf("Select your choice among following options:\n");
	    printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save Database\n");
	    printf("Enter your choice\n");
	    scanf(" %d", &choice);
	    switch(choice)
	    {
		case 1:
		    if(flag == 1)
		    {
			printf("Database already created for given file(s)\n");
		    }
		    else
		    {
			create_database(&head, heads);
			flag = 1;
		    }
		    break;
		case 2:
		    display_database(heads);
		    break;
		case 3:
		    printf("Enter the file(source file) name to update data: ");
		    scanf("%s", src_file);
		    update_database(src_file, heads);
		    break;
		case 4:
		    printf("Enter the word you want to search: ");
		    scanf("%s", word);
		    search_word(word, heads);
		    break;
		case 5:
		    printf("Enter the file name to save the database: ");
		    scanf("%s", backup_file);
		    save_database(backup_file, heads);
		    break;
		default:
		    printf("Please Enter proper choice\n");
	    }
	    printf("Do you want to continue ?\n");
	    printf("Enter y/Y to continue and n/N to discontinue\n");
	    scanf(" %c", &option);

	}
    }
    else
    {
	printf("Please pass proper command line arguments\n");
	return 0;
    }
}
