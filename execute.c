#include "monty.h"

char *monty_opcode;

/**
 * opcode_match - check whether opcode matches any of the supported ones
 * @line: the command
 * @instructions: supported opcodes
 * @i: the opcode to compare
 * Return: 1 if true else 0
 */
int opcode_match(char *line, instruction_t *instructions, int i)
{
	char *prefix;
	size_t len;
	int valid_end = 0;

	prefix = instructions[i].opcode;
	len = strlen(prefix);
	if (strncmp(" ", &line[len], 1) == 0 || line[len] == '\0')
		valid_end = 1;
	if (strncmp(line, prefix, len) == 0 && valid_end)
		return (1);
	return (0);
}

/**
 * execute - executes the commands contained in the file
 * @file: the file containing monty bytes
 */
void execute(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	int is_valid, line_number = 1, i, num_instructions;
	instruction_t instructions[] = {
			{"push", handle_push}, {"pall", handle_pall},
			{"pint", handle_pint}, {"pop", handle_pop}
	};
	num_instructions = sizeof(instructions) / sizeof(instructions[0]);
	while (getline(&line, &len, file) != -1)
	{
		strip(line, NULL);
		if (strlen(line) == 0)
			continue;
		monty_opcode = line;
		is_valid = 0;
		for (i = 0; i < num_instructions; i++)
		{
			/* If the opcode starts with a known prefix, call the related function */
			if (opcode_match(line, instructions, i))
			{
				is_valid = 1;
				instructions[i].f(&stack, line_number);
			}
		}
		if (is_valid == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	fclose(file);
	free_stack(stack);
}
