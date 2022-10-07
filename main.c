#include "monty.h"
#define DELIM " \t\n\r"

/**
 *  * main - entry point
 *   * @ac: number of arguments
 *    * @av: arguments_
 *     * Return: 0 on Success
 */
int main(int ac, char *av[])
{
	FILE *ifp = fopen(av[1], "r");
	stack_t *stack = NULL;
	ssize_t read = 0;
	unsigned  int line_number = 0;
	size_t len = 0;
	char *aux = NULL;
	char *token = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (ifp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&aux, &len, ifp)) != -1)
	{
		line_number += 1;
		if (*aux != '\n')
		{
			token = strtok(aux, DELIM);
			if (token != NULL)
			{
				if (*token == '#')
					continue;
				if (check_push(token) != 0 && token != NULL)
					second = strtok(NULL, DELIM);
				else
					second = NULL;
				checkFunction(token, line_number, &stack);
			}
		}
	}
	free_list(stack);
	free(token);
	fclose(ifp);
	return (0);
}
