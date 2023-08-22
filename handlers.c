#include "main.h"

/**
 * handle_push - pushes a value to the stuck
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	push(stack, opcode_arg);
}

/**
 * handle_pop - removes the top value from the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	pop(stack);
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
 * handle_pint - prints the topmost element of the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!is_empty(*stack))
		printf("%d\n", (*stack)->n);
	else
		fprintf(stderr, "Stack is empty\n");
}
