#include "monty.h"

/**
 * handle_push - pushes a value to the stuck
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	char arg[1024];
	int value;

	set_arg(arg, "push");

	value = atoi(arg);

	if (value == 0 && strncmp(arg, "0", 1) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push(stack, value);
}

/**
 * handle_pop - removes the top value from the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	delete_at_index(stack, 0);
}

/**
 * handle_pint - prints the topmost element of the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * handle_pall - prints all the elements of the stack starting from the top
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}


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
