#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"
#include "preprocessor.h"
#include "first_pass.h"
#include "second_pass.h"
#include "code.h"
#include "file_maker.h"

/**
 * Processes a single assembly source file, will send errors if found to stderr.
 * @param filename The filename, without it's extension.
 */
static bool process_file(char *fileName);

/**
 * Entry point - 10bit assembler.
 */
int main(int argc, char **argv)
{
	int i;
	
	bool succes = TRUE;
	
	if(argc == 1)
	{
		printf("\nTo use the assembler add an assembly source file name to this command.\n");
		return 0;
	}
	
	for(i = 1; i < argc; i++)
	{
		if(!succes)/*will separate errors of file from file*/
		{
			puts(" ");
		}
		
		succes = process_file(argv[i]);
	}
	
	return 0;
}

/**
 * Frees all the linked lists that had been allocated.
 * @param pointer a pointer to struct of file info that holdes the linked list to be interpret.
 */
static void free_file_info(file_info * pointer);

/**
 * Processes a single assembly source file, will send errors if found to stderr.
 * @param filename The filename, without it's extension.
 */
static bool process_file(char *file_name)
{
	FILE *fp;
	
	char * full_file_name;
	
	file_info * file_info_pointer;
	
	
	file_info_pointer = (file_info *) calloc(1, sizeof(file_info));/*allot of things need to be zero thats why calloc.*/
	
	full_file_name = (char *) allocate_and_check(sizeof(char) * (strlen(file_name)+SPACE_FOR_EXTENSION));
	
	
	strcpy(full_file_name, file_name);
	
	strcat(full_file_name, ".as");
	
	fp = fopen(full_file_name, "r");
	
	if(fp == NULL)
	{
		printf("Error: file \"%s\" is inaccessible for reading.\n", full_file_name);
		
		free(full_file_name);
		
		free(file_info_pointer);
		
		return FALSE;
	}
	
	if(!preprocessor(fp, file_name))
	{
		return FALSE;
	}
	
	
	
	strcpy(full_file_name, file_name);
	
	strcat(full_file_name, ".am");
	
	fp = fopen(full_file_name, "r");
	
	if(fp == NULL)
	{
		printf("Error: file \"%s\" is inaccessible for reading.\n", full_file_name);
		
		free(full_file_name);
		
		free(file_info_pointer);
		
		return FALSE;
	}
	
	file_info_pointer->file_name = full_file_name;
	
	/*if no error do second part.*/
	if(first_pass(fp, file_info_pointer))
	{
		rewind(fp);
		
		if(second_pass(fp, file_info_pointer))
		{
			/*starting procedure to make .ob file.*/
			strcpy(full_file_name, file_name);
			
			strcat(full_file_name, ".ob");
			
			fp = fopen(full_file_name, "w");
			if(fp == NULL)
			{
				printf("Error: file \"%s\" is inaccessible for writting.\n", full_file_name);	
			}
			
			make_file_object(fp, file_info_pointer);
				
			if(file_info_pointer->is_file_entry)
			{
				/*starting procedure to make .ent file.*/
				strcpy(full_file_name, file_name);
			
				strcat(full_file_name, ".ent");
		
				fp = fopen(full_file_name, "w");
				if(fp == NULL)
				{
					printf("Error: file \"%s\" is inaccessible for writting.\n", full_file_name);	
				}
		
				make_file_entry(fp, file_info_pointer);
			}
			
			if(file_info_pointer->is_file_extern)
			{	
				/*starting procedure to make .ent file.*/
				strcpy(full_file_name, file_name);
			
				strcat(full_file_name, ".ext");
			
				fp = fopen(full_file_name, "w");
				if(fp == NULL)
				{
					printf("Error: file \"%s\" is inaccessible for writting.\n", full_file_name);	
				}
			
				make_file_extern(fp, file_info_pointer);
			}
		}
	}
	
	/*no matter what making sure free all alocated data.*/
	free_file_info(file_info_pointer);
	
	return file_info_pointer->is_file_good;
}

/**
 * Frees all the linked lists that had been allocated.
 * @param pointer a pointer to struct of file info that holdes the linked list to be interpret.
 */
static void free_file_info(file_info * pointer)
{
	void * temp;
	
	free(pointer->file_name);
	
	while(pointer->list_head_label != NULL)
	{
		free(pointer->list_head_label->label_name);
		
		temp = pointer->list_head_label;
		
		pointer->list_head_label = pointer->list_head_label->next;
		
		free((label_node *) temp);
	}
	
	while(pointer->list_head_data != NULL)
	{
		temp = pointer->list_head_data;
		
		pointer->list_head_data = pointer->list_head_data->next;
		
		free((data_node *) temp);
	}
	
	while(pointer->list_head_command != NULL)
	{
		temp = pointer->list_head_command;
		
		pointer->list_head_command = pointer->list_head_command->next;
		
		free((command_node *) temp);
	}
	
	while(pointer->list_head_extern != NULL)
	{
		free(pointer->list_head_extern->label_name);
		
		temp = pointer->list_head_extern;
		
		pointer->list_head_extern = pointer->list_head_extern->next;
		
		free((extern_node *) temp);
	}
}


