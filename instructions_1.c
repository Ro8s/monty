#include "monty.h"

int push(stack_t **list, unsigned int line)
{
	int i, num;
	char *cadena;
	stack_t *nodo;
	stack_t *search = *list;

	cadena = strtok(NULL, " \n\t");
	for (i = 0; cadena[i]; i++)
	{
		if (!isdigit(cadena[i]))
		{
			fprintf(stderr, "L%d: usage: push integer", line);
			/* free_list(list); */
			return (-1);
		}
	}
	num = atoi(cadena);
	nodo = malloc(sizeof(stack_t));
	if (!nodo)
	{
		fprintf(stderr, "Error: malloc failed");
		/* free_list(list); */
		return (-1);
	}
	nodo->n = num;
	if (!*list)
	{
		nodo->next = NULL;
		nodo->prev = NULL;
		*list = nodo;
		return (0);
	}
	for (i = 0; search->next; i++)
		search = search->next;
	nodo->next = NULL;
	nodo->prev = search;
	search->next = nodo;
	return (0);
} 