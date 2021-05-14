#include "monty.h"
/**
 * add - addition between the previous and the top element.
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = aux->n + aux->prev->n;
	aux->prev->n = sum;
	aux->prev->next = NULL;
	free(aux);
}
/**
 * sub - subtraction between the previous and the top element.
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void sub(stack_t **list, unsigned int line)
{
	stack_t *aux = *list;
	int res;

	aux = last_list_check(aux);
	if (!aux)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if (aux->prev->n < 0)
		res = aux->prev->n + aux->n;
	else
		res = aux->prev->n - aux->n;

	aux->prev->n = res;
	aux->prev->next = NULL;
	free(aux);
}

/**
 * div_f - divides the last two nodes.
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void div_f(stack_t **list, unsigned int line)
{
	stack_t *last, *before;

	last = last_list_check(*list);
	if (!last)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if (last->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	before = last->prev;
	before->n = before->n / last->n;
	before->next = NULL;
	free(last);
}

/**
 * mul - multiplies the last two nodes.
 * @list: header of the list.
 * @line: line of the command.
 * ---------------------
 */
void mul(stack_t **list, unsigned int line)
{
	stack_t *aux = *list;
	int mul;

	aux = last_list_check(aux);
	if (!aux)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	mul = aux->n * aux->prev->n;
	aux->prev->n = mul;
	aux->prev->next = NULL;
	free(aux);
}
