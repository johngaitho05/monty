#include "monty.h"

/**
 * node_at_index - get node at the given index
 * @head: pointer to the head node
 * @index: the position of the node in the list
 * Return: node at the given index if it exists else NULL
 */
stack_t *node_at_index(stack_t *head, unsigned int index)
{
	stack_t *current = head;
	unsigned int i = 0;

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	return (current);
}
