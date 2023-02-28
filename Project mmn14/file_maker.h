#ifndef _FILE_MAKER_H
#define _FILE_MAKER_H


/**
 * Processes a linked list with assembly commands and data, makes a file with the file name and puts 
 * the machine language in the file that was interpret.
 * @param fp The File to put the machine language.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be interpret.
 */
void make_file_object(FILE * fp, file_info * file_info_pointer);

/**
 * Processes a linked list that hold label data, makes a file with the file name and puts 
 * the label name that is been declared entry in the file and after it the addres.
 * @param fp The File to put the label name and addres.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be processed.
 */
void make_file_entry(FILE * fp, file_info * file_info_pointer);

/**
 * Processes a linked list that hold label data, makes a file with the file name and puts every time
 * the label name that is declared extern had been used in the file and after it the addres it was used..
 * @param fp The File to put the label name and addres.
 * @param file_info_pointer a pointer to struct of file info that holdes the linked list to be processed.
 */
void make_file_extern(FILE * fp, file_info * file_info_pointer);



#endif

