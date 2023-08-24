#include "monty.h"


/**
 * handle_add - adds the top two elements and stores
 * the results in the first node
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_add(stack_t **stack, unsigned int line_number)
{

	int result;
	stack_t *first, *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = node_at_index(*stack, 0);
	second = node_at_index(*stack, 1);

	result = first->n + second->n;

	second->n = result;
	(*stack) = second;

	free(first);
}

/**
 * handle_sub - subtracts the top two elements of a stack from the
 * top two elements
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	int result;
    stack_t *first,*second;
	(void)line_number;

    if (stack_len(*stack) < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    second = node_at_index(*stack, 1);
    first = node_at_index(*stack, 0);

    result = first->n - second->n;
    second->n = result;
    second = *stack;

    free(first);

}
void handle_div(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void handle_mul(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void handle_mod(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
