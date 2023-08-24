#include "monty.h"

/**
 * handle_swap - swaps the top two elements
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{

	stack_t *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);

	}
	second = (*stack)->next;

	(*stack)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *stack;
	second->next = *stack;
	second->prev = NULL;
	(*stack)->prev = second;

	(*stack) = second;
}