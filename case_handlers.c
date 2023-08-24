#include "monty.h"

/**
 * handle_nop - does nothing
 * the results in the first node
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * handle_pchar - prints the number represented
 * by the int value of the top node
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_code;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	ascii_code = (*stack)->n;

	if (ascii_code < 26 || ascii_code > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)ascii_code);
}
