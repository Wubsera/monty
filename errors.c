#include "monty.h"

/**
 *  * _errors - manages the errors-
 *   * @errornum: number of error
 *    * @line_number: line number read
 *     * @stack: pointer to list's head
 */
void _errors(int errornum, unsigned int __attribute__((unused)) line_number,
		stack_t **stack)
{
	char *malloc_f = "Error: malloc failed\n";

	if (errornum == 1)
	{
		free_list(*stack);
		write(2, malloc_f, strlen(malloc_f));
		exit(EXIT_FAILURE);
	}
	if (errornum == 2) /*Incorrect use of push*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 3) /*pint failed*/
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 4) /*pop failed*/
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 5) /*swap failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 6) /*add failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 *  * _errors2 - manages the errors
 *   * @errornum: number of error
 *    * @line_number: line number read
 *     * @stack: pointer to list's head
 */
void _errors2(int errornum, unsigned int __attribute__((unused)) line_number,
		stack_t **stack)
{
	if (errornum == 7) /*sub failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 8) /*div failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 9) /*mul failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 10) /*mul failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	if (errornum == 11) /*pchar failed*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
}
