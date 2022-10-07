#include "monty.h"

/**
 *  * f_mod - calcs the module of the two top elements on the stack
 *   * @head: This is the list head:
 *    * @line_number: Line number read
 *     *
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	int mod;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors2(10, line_number, head); /* mod failed */
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	mod = (*head)->next->n % (*head)->n;
	f_pop(head, line_number);
	(*head)->n = mod;
}



/**
 *  * f_pchar -  prints the char at the top of the stack, followed by a new line
 *   *
 *    * @head: This is the list head
 *     * @line_number: Line number read
 *      *
 */
void f_pchar(stack_t **head, unsigned int line_number)
{

	if (*head == NULL)
	{
		_errors2(11, line_number, head); /* pchar failed */
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 *  * f_pstr - prints the string starting at the top of the stack,
 *   *          followed by a new line.
 *    *
 *     * @head: This is the list head
 *      * @line_number: Line number read
 *       *
 */ 
void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (*head == NULL)
	{
		printf("\n");
		return;
	}
	while (aux != NULL)
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 *  * f_rotl - The opcode rotl rotates the stack to the top
 *   *          The top element of the stack becomes the last one, and the second
 *    *          top element of the stack becomes the first one
 *     *
 *      * @head: This is the list head
 *       * @line_number: Line number read
 *        *
 */
void f_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *aux, *new_node;

	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		return;
	}
	new_node = (stack_t *) malloc(sizeof(stack_t));

	if (new_node == NULL)
		_errors(1, line_number, head); /* Failed malloc */

	new_node->n = (*head)->n;
	f_pop(head, line_number);
	aux = (*head);
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->next = new_node;
			new_node->prev = aux;
			new_node->next = NULL;
			break;
		}
		aux = aux->next;
	}
}

/**
 *  * f_rotr - The opcode rotr rotates the stack to the bottom.
 *   *          The last element of the stack becomes the top element of the stack
 *    *
 *     * @head: This is the list head
 *      * @line_number: Line number read
 *       *
 */

void f_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head, *last = *head;

	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		return;
	}
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->next = last;
			last->prev = aux;
			aux->prev->next = NULL;
			aux->prev = NULL;
			(*head) = aux;
			break;
		}
		aux = aux->next;
	}
	(void)line_number;
}
