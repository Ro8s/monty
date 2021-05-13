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
		fprintf(stderr, "L%d: can't pint, stack empty\n",line);
		exit(EXIT_FAILURE);
	}
	for (i = 0; aux->next; i++)
		aux = aux->next;
	printf("%d\n", aux->n);
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

	if(!*list)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if((*list)->next == NULL)
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
