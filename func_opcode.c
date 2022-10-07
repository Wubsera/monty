#include "monty.h"

/**
 *  * f_push - adds a new element into the stack
 *   * @stack: pointer to list's head
 *    * @line_number: line number read_
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		free(second);
		_errors(1, line_number, stack); /* Failed malloc */
	}
	if (second == NULL || _parseArg(second) == 0)
	{
		free(new_node);
		_errors(2, line_number, stack); /* Bad use of push */
	}
	if ((isdigit(*second) != 0) || (*second == '-' && isdigit(second[1])))
		new_node->n = atoi(second);

	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	(*stack) = new_node;
}

/**
 *  * f_pall - prints the stacks, from last added to first
 *   * @head: pointer to list's head
 *    * @line_number: line number read
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (aux == NULL)
		return;

	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
	(void)line_number;
}

/**
 *  * f_pint - prints the last element added to the stack
 *   * @head: pointer to list's head
 *    * @line_number: line number read
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
		_errors(3, line_number, head); /*pint failed*/

	printf("%d\n", (*head)->n);
}
/**
 *  * f_pop - removes the last element added to the stack
 *   * @head: pointer to list's head
 *    * @line_number: line number read
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (aux == NULL)
		_errors(4, line_number, head); /* pop failed */

	else if (aux->prev == NULL && aux->next == NULL)
	{
		free(aux);
		*head = NULL;
	}
	else if (aux->next != NULL)
	{
		*head = aux->next;
		(*head)->prev = NULL;
		free(aux);
	}
}
/**
 *  * f_swap - swaps the value of the last two elements added to the stack
 *   * @stack: pointer to list's head
 *    * @line_number: line number read
 */

void f_swap(stack_t **stack, unsigned int line_number)
{
	int swap_aux;

	if ((*stack) == NULL)
		_errors(5, line_number, stack); /* Swap failed */
	else if ((*stack)->prev == NULL && (*stack)->next == NULL)
		_errors(5, line_number, stack);
	else
	{
		swap_aux = (*stack)->n;
		(*stack)->n = ((*stack)->next)->n;
		(*stack)->next->n = swap_aux;
	}
}
