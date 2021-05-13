#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
extern typedef struct global_var
{
	FILE *file;
	char *buffer;
} global_t;
*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ------------- Prototypes -------------  */

/* Regular prototypes */
void error_checker(int ac, char **av);
void line_processor(unsigned int, FILE *, stack_t **, char *);
void free_list(stack_t **list);
void free_buffer(char *buffer);
void close_file(FILE *file);
void error_unk_ins(unsigned int line, char *token);
void error_push(unsigned int line);

/* Instruction prototypes */
void push(stack_t **list, unsigned int line);
void pall(stack_t **list, unsigned int line);
void pint(stack_t **list, unsigned int line);


#endif /* ifndef MONTY_H */
