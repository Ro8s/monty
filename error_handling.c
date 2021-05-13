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


void error_unk_ins(stack_t *list, char *buffer, unsigned int line, char *token)
{
	free_list(&*list);
	free(buffer);
	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}
