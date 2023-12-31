#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct global_s - global variables
 * @arg: the opcode argument
 * @stack: the insertion mode (1 for stack, 0 for queue)
 */
typedef struct global_s
{
	char *arg;
	int stack;
} global_t;

extern global_t env;

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

char *remove_comment(char *line);
int opcode_match(char *line, instruction_t *instructions, int i);
int count_instructions(instruction_t *instructions);
void set_arg(char *arg, char *command);
char *strip(char *str, char *tokens);
int opcode_match(char *line, instruction_t *instructions, int i);
stack_t *push(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *head);
int delete_at_index(stack_t **head, unsigned int index);
size_t stack_len(const stack_t *h);
stack_t *node_at_index(stack_t *head, unsigned int index);
stack_t *insert_at_end(stack_t **head, const int n);
void handle_push(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);
void handle_div(stack_t **stack, unsigned int line_number);
void handle_mul(stack_t **stack, unsigned int line_number);
void handle_mod(stack_t **stack, unsigned int line_number);
void handle_pchar(stack_t **stack, unsigned int line_number);
void handle_pstr(stack_t **stack, unsigned int line_number);
void handle_rotl(stack_t **stack, unsigned int line_number);
void handle_rotr(stack_t **stack, unsigned int line_number);
void handle_stack(stack_t **stack, unsigned int line_number);
void handle_queue(stack_t **stack, unsigned int line_number);
void execute(FILE *file);
#endif
