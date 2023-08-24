#include "monty.h"

/**
 * handle_rotl - moves the top element to the bottom
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_rotl(stack_t **stack, unsigned int line_number)
{

	stack_t *head, *second, *last;
	size_t len = stack_len(*stack);

	(void)line_number;
	if (len < 2)
		return;

	head = *stack;
	second = (*stack)->next;
	last = node_at_index(*stack, len - 1);
	last->next = head;
	head->next = NULL;
	second->prev = NULL;
	(*stack) = second;

}

/**
 * handle_rotr - moves the bottom element to the top
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *second_last, *last;
	size_t len = stack_len(*stack);

	(void)line_number;
	if (len < 2)
		return;

	head = *stack;
	last = node_at_index(*stack, len - 1);
	second_last = last->prev;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	second_last->next = NULL;
	(*stack) = last;
}


/**
 * handle_stack - sets insertion mode to stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	env.stack = 1;
}

/**
 * handle_queue - sets insertion mode to queue
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void handle_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	env.stack = 0;
}

