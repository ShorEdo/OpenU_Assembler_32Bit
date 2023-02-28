#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"


/**
 * Function that translates 10 bit word of a binary data to a 32 based data.
 *
 * @param pointer a pointer to array of chars that will holde interpreted 32 base data, needs to be 3 char length.
 * @param data a union that holds the data to interpret.
 */
static void interpeter(char * pointer, machine_language data);

/**
 * Processes a linked list that hold label data, makes a file with the file name and puts every time
 * the label name that is declared extern had been used in the file and after it the addres it was used..
 * @param fp The File to put the label name and addres.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be processed.
 */
void make_file_extern(FILE * fp, file_info * file_info_pointer)
{
	char addres[MAX_MACHINE_LENGTH + 1];
	
	extern_node * current_node;
	
	machine_language bit = {0};
	
	
	current_node = file_info_pointer->list_head_extern;
	
	while(current_node != NULL)
	{
		bit.combined = current_node->addres + MEMORY_LOCATION_START;/*adds the starting memory.*/
		
		interpeter(addres, bit);
		
		fprintf(fp, "%s %s\n", current_node->label_name, addres);
		
		current_node = current_node->next;
	}
}

/**
 * Processes a linked list that hold label data, makes a file with the file name and puts 
 * the label name that is been declared entry in the file and after it the addres.
 * @param fp The File to put the label name and addres.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be processed.
 */
void make_file_entry(FILE * fp, file_info * file_info_pointer)
{
	char addres[MAX_MACHINE_LENGTH + 1];	
	
	label_node * current_node;
	
	machine_language bit = {0};
	
	
	current_node = file_info_pointer->list_head_label;
	
	while(current_node != NULL)
	{
		if(current_node->type == LABEL_IS_ENTRY)
		{
			bit.combined = current_node->label_addres + MEMORY_LOCATION_START;
		
			interpeter(addres, bit);
			
			fprintf(fp, "%s %s\n", current_node->label_name, addres);
		}
		
		current_node = current_node->next;
	}
}

/**
 * Processes a linked list with assembly commands and data, makes a file with the file name and puts 
 * the machine language in the file that was interpret.
 * @param fp The File to put the machine language.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be interpret.
 */
void make_file_object(FILE * fp, file_info * file_info_pointer)
{
	/*two machine arrays for the prints.*/
	char first[MAX_MACHINE_LENGTH + 1], second[MAX_MACHINE_LENGTH + 1];
	
	unsigned int i;
	/*nodes that will beused to fetch the data.*/
	command_node * command_node;
	
	data_node * instruct_node;

	machine_language bit_first = {0}, bit_second = {0};
	
	
	bit_first.combined = file_info_pointer->IC;
	
	bit_second.combined = file_info_pointer->DC;
	
	interpeter(first, bit_first);
	
	interpeter(second, bit_second);
	
	
	/*this setups the title numbers.*/
	if(bit_first.combined <= MAX_MACHINE_NUMBER)
	{
		first[0] = first[1];
		first[1] = '\0';
	}
	if(bit_second.combined <= MAX_MACHINE_NUMBER)
	{
		second[0] = second[1];
		second[1] = '\0';
	}
	/*print title.*/
	fprintf(fp, "%s %s\n",first, second);
	
	
	command_node = file_info_pointer->list_head_command;
	
	i = MEMORY_LOCATION_START;
	
	while(command_node != NULL)
	{
		/*process to compute the addres and code.*/
		bit_first.combined = i;
		
		bit_second.combined = command_node->data;
		
		interpeter(first, bit_first);
		
		interpeter(second, bit_second);
		
		fprintf(fp, "%s %s\n",first, second);
		
		i++;
		
		command_node = command_node->next;
	}
	
	
	instruct_node = file_info_pointer->list_head_data;
	
	
	while(instruct_node != NULL)
	{
		/*same as before just for the instructions.*/
		bit_first.combined = i;
		
		bit_second.combined = instruct_node->data;
		
		interpeter(first, bit_first);
		
		interpeter(second, bit_second);
		
		fprintf(fp, "%s %s\n",first, second);
		
		i++;
		
		instruct_node = instruct_node->next;
	}
}

/**
 * Function that translates 10 bit word of a binary data to a 32 based data.
 * @param pointer a pointer to array of chars that will holde interpreted 32 base data, needs to be 3 char length.
 * @param data a union that holds the data to interpret.
 */
static void interpeter(char * pointer, machine_language data)
{
	static const char machine_number[] = "!@#$%^&*<>abcdefghijklmnopqrstuv";
	
	
	*pointer++ = machine_number[data.split.second];
	
	
	*pointer++ = machine_number[data.split.first];
	
	*pointer = '\0';
}




