#include "monty.h"

/**
 * main - main function of monty
 * @ac: number of arguments
 * @av: arguments
 * Return: success or failure
 */
int main(int ac, char **av)
{
	FILE *file_pointer;
	stack_t *list;
	unsigned int line;
	char *buffer = NULL;
	size_t size = 32;

	list = NULL;
	error_checker(ac, av);

	file_pointer = fopen(av[1], "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(free_list, &list);
	on_exit(free_buffer, &buffer);
	on_exit(close_file, file_pointer);

	for (line = 1; line; line++)
	{
		if (getline(&buffer, &size, file_pointer) == -1)
			break;
		line_processor(line, &list, buffer);
	}

	exit(EXIT_SUCCESS);
}

/**
 * line_processor - Process and evaluates each line
 * @buffer: Line read
 * @line: Line being processed
 * @list: Linked list to pass to the function
 * ---------------------------
 * Return: -1 if error, 0 if success
 */

void line_processor(unsigned int line, stack_t **list, char *buffer)
{
	char *token;
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{NULL, NULL}
	};

	token = strtok(buffer, " \n\t");
	if (!token)
		return;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(token, "nop") == 0 || token[0] == '#')
			break;
		if (strcmp(token, instructions[i].opcode) == 0)
		{
			instructions[i].f(&*list, line);
			break;
		}
	}
	if (!instructions[i].opcode)
		error_unk_ins(line, token);
}
