#include "monty.h"

/**
 * free_list - Frees a list
 * @list: list to free
 * ---------------
 */
void free_list(stack_t **list)
{
	stack_t *fire;

	if (!*list)
		return;

	fire = *list;

	for (; *list;)
	{
		fire = *list;
		*list = (*list)->next;
		free(*fire);
	}
}

/**
 * free_buffer - Frees the buffer of the getline
 * @buffer: Buffer to liberate
 * ------------
 */
void free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
}

/**
 * close_file - Closes the file passed
 * @file: File to close
 * ---------------
 */
void close_file(FILE *file)
{
	fclose(file);
}


