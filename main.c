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

	list = NULL;
	error_checker(ac, av);

	file_pointer = fopen(av[1], "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	for (line = 1; line; line++)
	{
		if (getline(&buffer, &size, file) == -1)
		{
			free(buffer);
			break;
		}
		line_processor(line, file_pointer, &list);
	}
	
	free_list(&list);
	fclose(file_pointer);
	return (EXIT_SUCCESS);
}

/**
 * line_processor - Process and evaluates each line
 * @line: Line being processed
 * @file: File to read
 * @list: Linked list to pass to the function
 * ---------------------------
 * Return: -1 if error, 0 if success
 */

void line_processor(unsigned int line, FILE *file, stack_t **list)
{
	char *token;
	size_t size = 32, i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
		/*
		 *{"pop", pop},
		 *{"swap", swap},
		 *{"add", add},
		 *{"nop", nop},
		 *{"sub", sub},
		 *{"div", div},
		 *{"mul", mul},
		 *{"mod", mod},
		 *{NULL, NULL}
		*/
	};

	token = strtok(buffer, " \n\t");
	if (!token)
		continue;

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(token, instructions[i].opcode) == 0)
		{
			instructions[i].f(&*list, line);
			break;
		}
	if (!instructions[i].opcode)
		error_unk_ins(&**list, &*buffer, line, token);
}
