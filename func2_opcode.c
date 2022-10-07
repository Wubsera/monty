#include "monty.h"

/**
 *  * f_nop - does nothing
 *   * @stack: pointer to list's head_
 *    * @line_number: line number read
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	return;
	(void)line_number;
	(void)**stack;
}

/**
 *  * f_add - Adds two top elements on the stack
 *   * @head: This is the list head
 *    * @line_number: Line number read
 *     *
 */

void f_add(stack_t **head, unsigned int line_number)
{
	int sum;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors(6, line_number, head); /* Add failed */

	sum = (*head)->n + (*head)->next->n;
	f_pop(head, line_number);
	(*head)->n = sum;
}

/**
 *  * f_sub - substracts the two top elements on the stack
 *   * @head: This is the list head
 *    * @line_number: Line number read
 *     *
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	int sub;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors2(7, line_number, head); /* sub failed */

	sub = (*head)->next->n - (*head)->n;
	f_pop(head, line_number);
	(*head)->n = sub;
}

/**
 *  * f_div - divides the two top elements on the stack
 *   * @head: This is the list head
 *    * @line_number: Line number read
 *     *
 */
void f_div(stack_t **head, unsigned int line_number)
{
	int div;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors2(8, line_number, head); /* div failed */
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	div = (*head)->next->n / (*head)->n;
	f_pop(head, line_number);
	(*head)->n = div;
}

/**
 *  * f_mul - multiplies the two top elements on the stack
 *   * @head: This is the list head
 *    * @line_number: Line number read
 *     *
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	int mul;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors2(9, line_number, head); /* sub failed */

	mul = (*head)->next->n * (*head)->n;
	f_pop(head, line_number);
	(*head)->n = mul;
}
