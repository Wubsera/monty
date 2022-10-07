#include "monty.h"

/**
 *  * free_list - frees a list_
 *   * @stack: pointer to list's head
 */
void free_list(stack_t *stack)
{
	stack_t *aux = stack;

	while (aux != NULL)
	{
		stack_t *next = aux->next;

		free(aux);
		aux = next;
	}
}
