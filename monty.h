#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *second;
/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue):
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
		int n;
			struct stack_s *prev;
				struct stack_s *next;
} stack_t;


/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
			void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Functions that check for errors */
void _errors(int errornum, unsigned int line_number, stack_t **stack);
void _errors2(int errornum, unsigned int __attribute__((unused)) line_number,
			      stack_t **stack);

/* Checks if the line read is a valid argument */
void checkFunction(char *token, unsigned int line_number, stack_t **head);

/* Checks if the argument read is push */
int check_push(char *s);

/* Checks if second argument is an integer */
int _parseArg(char *c);

/* Frees the list */
void free_list(stack_t *stack);

/* Op_code functions */
void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void f_pint(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_nop(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
void f_sub(stack_t **head, unsigned int line_number);
void f_mul(stack_t **head, unsigned int line_number);
void f_div(stack_t **head, unsigned int line_number);
void f_mod(stack_t **head, unsigned int line_number);
void f_pchar(stack_t **head, unsigned int line_number);
void f_pstr(stack_t **head, unsigned int line_number);
void f_rotl(stack_t **head, unsigned int line_number);
void f_rotr(stack_t **head, unsigned int line_number);
#endif /* MONTY_H */
