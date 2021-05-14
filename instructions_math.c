#include "monty.h"
/**
 * add - prints all the values on the stack from the top
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void add(stack_t **list, unsigned int line)
{
	stack_t *aux = *list;
	int sum;

	aux = last_list_check(aux);
	if (!aux)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}
	sum = aux->n + aux->prev->n;
	aux->prev->n = sum;
	aux->prev->next = NULL;
	free(aux);
}
