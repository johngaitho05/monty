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
	second->prev = NULL;
	first->next = NULL;
	(*stack) = second;

	free(first);
}

/**
 * handle_sub - subtracts the top element from the top second element
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *first, *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = node_at_index(*stack, 0);
	second = node_at_index(*stack, 1);

	result = second->n - first->n;

	second->n = result;
	second->prev = NULL;
	first->next = NULL;
	(*stack) = second;

	free(first);
}

/**
 * handle_div - divide the second element by the top element
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *first, *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = node_at_index(*stack, 0);
	second = node_at_index(*stack, 1);
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = second->n / first->n;
	second->n = result;
	second->prev = NULL;
	first->next = NULL;
	(*stack) = second;

	free(first);
}

/**
 * handle_mul - multiplies the second element by first element
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *first, *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = node_at_index(*stack, 0);
	second = node_at_index(*stack, 1);

	result = second->n * first->n;

	second->n = result;
	second->prev = NULL;
	first->next = NULL;
	(*stack) = second;

	free(first);
}

/**
 * handle_mod - find the remainder of dividing second element by first element
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_mod(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *first, *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = node_at_index(*stack, 0);
	second = node_at_index(*stack, 1);
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = second->n % first->n;

	second->n = result;
	second->prev = NULL;
	first->next = NULL;
	(*stack) = second;

	free(first);
}
