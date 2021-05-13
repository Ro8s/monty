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
	unsigned int line = 1;

	list = NULL;
	error_checker(ac, av);

	file_pointer = fopen(av[1], "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_processor(line, file_pointer, &list);
	/*
	for (i = 0; list; i++)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
	*/
	free_list(&*list);
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
	char *buffer = NULL, *token;
	size_t size = 32;
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
		/*
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
		*/
	};

	for (line = 1; line; line += 1)
	{
		if (getline(&buffer, &size, file) == -1)
		{
			free(buffer);
			return;
		}
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
		{
			free_list(&**list);
			free(buffer);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * error_checker - checks for the basic errors
 * @ac: Number of parameters
 * @av: Parameters
 * -------------------
 * Returns: 1 if fails, 0 if success
 */
void error_checker(int ac, char **av)
{
	int ultimo;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ultimo = strlen(av[1]);
	if (av[1][ultimo - 1] != 'm' && av[1][ultimo - 2] != '.')
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}
