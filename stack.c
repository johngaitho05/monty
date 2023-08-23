#include "monty.h"

/**
 * create_node - Creates a new node with the given data
 * @data: The data to be stored in the node
 *
 * Return: Pointer to the newly created node
 */
stack_t *create_node(int data)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		perror("MError: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * push - Adds an element to the top of the stack
 * @top: Pointer to the top of the stack
 * @data: The data to be pushed onto the stack
 */
void push(stack_t **top, int data)
{
	stack_t *new_node = create_node(data);

	new_node->next = *top;
	if (*top != NULL)
		(*top)->prev = new_node;
	*top = new_node;
}

/**
 * pop - Removes an element from the top of the stack
 * @top: Pointer to the top of the stack
 *
 * Return: The data of the popped element
 */
int pop(stack_t **top)
{
	int data = (*top)->n;
	stack_t *temp = *top;
	*top = (*top)->next;

	if (*top == NULL)
	{
		fprintf(stderr, "Stack is empty\n");
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	if (*top != NULL)
		(*top)->prev = NULL;

	free(temp);
	return (data);
}

/**
 * is_empty - Checks if the stack is empty
 * @top: Pointer to the top of the stack
 *
 * Return: 1 if the stack is empty, 0 otherwise
 */
int is_empty(stack_t *top)
{
	return (top == NULL);
}

/**
 * print_stack - Prints the contents of the stack
 * @top: Pointer to the top of the stack
 */
void print_stack(stack_t *top)
{
	stack_t *current = top;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
