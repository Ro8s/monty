#include "monty.h"

/**
 * free_list - Frees a list
 * @list: list to free
 * ---------------
 */
void free_list(stack_t *list)
{
    stack_t *fire;

    if (!list)
        return;

    fire = list;

    for (; list;)
    {
        fire = list;
        list = list->next;
        free(fire);
    }
}