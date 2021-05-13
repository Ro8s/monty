#include "monty.h"

void push(stack_t **list, unsigned int line)
{
	int i, num;
	char *cadena;
	stack_t *nodo;
	stack_t *search = *list;

	cadena = strtok(NULL, " \n\t");
	for (i = 0; cadena[i]; i++)
		if (!isdigit(cadena[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_list(&**list);
			exit(EXIT_FAILURE);
		}

	num = atoi(cadena);
	nodo = malloc(sizeof(stack_t));
	if (!nodo)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(&**list);
		exit(EXIT_FAILURE);
	}
	nodo->n = num;
	if (!*list)
	{
		nodo->next = NULL;
		nodo->prev = NULL;
		*list = nodo;
		return;
	}
	for (i = 0; search->next; i++)
		search = search->next;
	nodo->next = NULL;
	nodo->prev = search;
	search->next = nodo;
}
