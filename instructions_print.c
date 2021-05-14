#include "monty.h"

/**
 * pall - prints all the values on the stack from the top
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void pall(stack_t **list, unsigned int line __attribute__((unused)))
{
	stack_t *aux = *list;
	int i;

	if (!aux)
		return;

	for (i = 0; aux->next; i++)
		aux = aux->next;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}
/**
 * pint - prints the value at the top from the stack
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void pint(stack_t **list, unsigned int line)
{
	stack_t *aux = *list;
	int i;

	if (!aux)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	for (i = 0; aux->next; i++)
		aux = aux->next;
	printf("%d\n", aux->n);
}
