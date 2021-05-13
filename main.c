#include "monty.h"
/**
 * main - main function of monty
 * @ac: number of arguments
 * @av: arguments
 * Return: success or failure
 */
int main(int ac, char **av)
{
	int line = 0, i, status;
	FILE *file_pointer;
	stack_t *list;

	list = NULL;
	if (error_checker(ac, av))
		exit(EXIT_FAILURE);

	file_pointer = fopen(av[1], "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	status = line_processor(line, file_pointer, &list);
	if (status == -1)
		exit(EXIT_FAILURE);

	for (i = 0; list; i++)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
	fclose(file_pointer);
	return (0);
}

/**
 * line_processor - Process and evaluates each line
 * @line: Line being processed
 * @file: File to read
 * @list: Linked list to pass to the function
 * ---------------------------
 * Return: -1 if error, 0 if success
 */

int line_processor(int line, FILE *file, stack_t **list)
{
	char *buffer = NULL, *token;
	size_t size = 32;
	int i;
	instruction_t instructions[] = {
		{"push", push}
		/*
		{"pall", pall},
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
		/*printf("%d ---------\n", line);*/
		if (getline(&buffer, &size, file) == -1)
			return (EXIT_SUCCESS);

		token = strtok(buffer, " \n\t");
		if (strcmp(token, "") == 0)
			continue;

		for (i = 0; instructions[i].opcode; i++)
			if (strcmp(token, instructions[i].opcode) == 0)
			{
				if (instructions[i].f(&*list, line) == -1)
				{
					i = -1;
					break;
				}
			}

		if (i == -1 || !instructions[i].opcode)
		{
			/* free_list(list); */			
			free(buffer);	
			if (i != -1)
				fprintf(stderr, "L%d: unknown instruction %s", line, token);
			return (-1);
		}
	}
	printf("Que haces aquí kpo?\n");
	return (-1);
}

/**
 * error_checker - checks for the basic errors
 * @ac: Number of parameters
 * @av: Parameters
 * -------------------
 * Returns: 1 if fails, 0 if success
 */
int error_checker(int ac, char **av)
{
	int ultimo;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	ultimo = strlen(av[1]);
	if (av[1][ultimo - 1] != 'm' && av[1][ultimo - 2] != '.')
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	return (0);
}
