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
