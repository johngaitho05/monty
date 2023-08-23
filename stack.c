#include "monty.h"

/**
 * push - adds a node at the beginning of the dll
 * @head: head node of the dll
 * @n: value of the nee node
 * Return: the newly inserted node if successful else NULL
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * print_stack - prints all elements of a stack_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_stack(const stack_t *h)
{
	const stack_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
		n++;
	}

	return (n);
}

/**
 * free_stack -frees a dll by deleting all nodes
 * @head: pointer to head node
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head->next;
		if (current != NULL)
			current->prev = NULL;
		free(head);
		head = current;
	}
}
