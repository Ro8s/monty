#include "monty.h"

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

/**
 * error_unk_ins - Function to avoid betty
 * @list: list to free
 * @buffer: buffer to free
 * @line: Line being evaluated
 * @token: token to print in the error message
 * ------------------
 */
void error_unk_ins(stack_t *list, char *buffer, unsigned int line, char *token)
{
	free_list(&*list);
	free(buffer);
	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}

/**
 * error_push - Another function to avoid betty
 * @list: list to free
 * @line: Line being evaluated
 * ------------------
 */
void error_push(stack_t *list, unsigned int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	free_list(&*list);
	exit(EXIT_FAILURE);
}
