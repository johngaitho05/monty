#include "monty.h"

char *monty_opcode;

/**
 * free_stack - frees the stack memory
 * @head: pointer to the head node
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * execute - executes the commands contained in the file
 * @file: the file containing monty bytes
 * @env: environment variables
 */
void execute(FILE *file, char **env)
{
	stack_t *stack = NULL;
	char line[1024], *prefix;
	int line_is_valid, line_number = 1, i, num_instructions;
	instruction_t instructions[] = {
			{"push", handle_push},
			{"pop", handle_pop},
			{"pall", handle_pall},
			{"pint", handle_pint}
	};

	(void)env;
	num_instructions = sizeof(instructions) / sizeof(instructions[0]);
	/* Read the file line by line and execute each command */
	while (fgets(line, sizeof(line), file))
	{
		/* Remove trailing whitespaces and new line characters */
		strip(line, NULL);
		if (strlen(line) == 0)
			continue;
		monty_opcode = line;
		line_is_valid = 0;
		for (i = 0; i < num_instructions; i++)
		{
			/* If the opcode starts with a known prefix, call the related function */
			prefix = instructions[i].opcode;
			if (strncmp(line, prefix, strlen(prefix)) == 0)
			{
				line_is_valid = 1;
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (line_is_valid == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	free_stack(stack);
}
