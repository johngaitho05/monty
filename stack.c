#include "monty.h"

/**
 * push - adds a node at the beginning of the dll
 * @head: head node of the dll
 * @n: value of the nee node
 * Return: the newly inserted node if successful else NULL
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new;

	if (!env.stack) /* Insertion mode is queue (FIFO) */
		return (insert_at_end(head, n));

	new = malloc(sizeof(stack_t));
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

/**
 * stack_len - returns the number of nodes in a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t stack_len(const stack_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * delete_at_index - deltes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_at_index(stack_t **head, unsigned int index)
{
	stack_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL || stack_len(current) < index + 1)
		return (-1);

	if (!index)
	{
		(*head) = current->next;
		if (current->next)
			current->next->prev = NULL;
		current->next = NULL;
		free(current);
		return (1);
	}

	while (i < index)
	{
		current = current->next;
		i++;
	}

	current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current);

	return (1);
}
