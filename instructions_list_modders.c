#include "monty.h"

/**
 * push - Executes the push opcode
 * @list: List to modify
 * @line: Line being executed
 * --------------------
 */
void push(stack_t **list, unsigned int line)
{
	int i, num;
	char *cadena;
	stack_t *nodo;
	stack_t *search = *list;

	cadena = strtok(NULL, " \n\t");
	if (!cadena)
		error_push(line);
	if (cadena[0] == '-' && cadena[1] != '\0')
		i = 1;
	else
		i = 0;
	for (; cadena[i]; i++)
		if (!isdigit(cadena[i]))
			error_push(line);

	num = atoi(cadena);
	nodo = malloc(sizeof(stack_t));
	if (!nodo)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

/**
 * pop - delete the top element of the stack.
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void pop(stack_t **list, unsigned int line)
{
	stack_t *aux = *list;
	int i;

	if	(!*list)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if	((*list)->next == NULL)
	{
		*list = NULL;
		free(aux);
	}
	else
	{
		for (i = 0; aux->next; i++)
			aux = aux->next;
		aux->prev->next = NULL;
		free(aux);
	}
}
/**
 * swap - swaps the top two elements of the stack.
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void swap(stack_t **list, unsigned int line)
{
	int c = 1;
	stack_t *last = *list, *ant = *list;

	if (!*list)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	while (last->next)
	{
		last = last->next;
		ant = last->prev;
		c++;
	}
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		last->next = ant;
		ant->prev = last;
		ant->next = NULL;
		last->prev = NULL;
		*list = last;
	}
	else
	{
		last->prev = ant->prev;
		ant->prev->next = last;
		last->next = ant;
		ant->prev = last;
		ant->next = NULL;
	}
}

stack_t *last_list_check(stack_t *list)
{
	int line = 1;

	if (!*list)
		return (NULL);

	while (list->next->next)
	{
		list = list->next;
		line++;
	}
	if (c < 2)
		return (NULL);

	return (list);
}
