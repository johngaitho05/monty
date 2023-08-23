#ifndef MONTY_MAIN_H
#define MONTY_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern char *monty_opcode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strncmp(const char *str1, const char *str2, size_t n);
void *_memmove(void *dest, const void *src, size_t n);
char *strip(char *str, char *tokens);
stack_t *push(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *head);
void handle_push(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
int setenv(char ***env, char *name, char *value, int overwrite);
void execute(FILE *file);
#endif
