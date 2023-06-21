#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * The user does not give any file or more than one file to the program.
 * The file provided is not a file that can be opened or read.
 * The file provided contains an invalid instruction.
 * When the program is unable to malloc more memory.
 * When the parameter passed to the instruction "push" is not an int.
 * When the stack it empty for pint.
 * When the stack it empty for pop.
 * When stack is too short for operation.
 */
void error(int error_code, ...)
{
	va_list ag;
	char *op;
	int i;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			i = va_arg(ag, int);
			op = va_arg(ag, char *);
			printf("L%d: unknown instruction %s\n", i, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @error_code: The error codes are the following:
 * When the stack it empty for pint.
 * When the stack it empty for pop.
 * When stack is too short for operation.
 * Division by zero.
 */
void more_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int i;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			i = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			printf("L%d: can't %s, stack too short\n", i, op);
			break;
		case 9:
			printf("L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * The number inside a node is outside ASCII bounds.
 * The stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list ag;
	int i;

	va_start(ag, error_code);
	i = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			printf("L%d: can't pchar, value out of range\n", i);
			break;
		case 11:
			printf("L%d: can't pchar, stack empty\n", i);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
