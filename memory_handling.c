#include "monty.h"

/**
 * free_list - Frees a list
 * @list: list to free
 * ---------------
 */
void free_list(int status, void *arg)
{
	stack_t *fire;
	stack_t **list;

	(void)status;

	list = (stack_t **)arg;

	if (*list)
		for (; *list;)
		{
			fire = *list;
			*list = (*list)->next;
			free(fire);
		}
}

/**
 * free_buffer - Frees the buffer of the getline
 * @buffer: Buffer to liberate
 * ------------
 */
void free_buffer(int status, void *arg)
{
	char **buffer;

	(void)status;
	
	buffer = (char **)arg;
	if (*buffer)
		free(*buffer);
}

/**
 * close_file - Closes the file passed
 * @file: File to close
 * ---------------
 */
void close_file(int status, void *arg)
{
	FILE *file;

	(void)status;

	file = (FILE *)arg;
	fclose(file);
}


