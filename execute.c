#include "monty.h"

char *monty_opcode;

/**
 * execute - executes the commands contained in the file
 * @file: the file containing monty bytes
 */
void execute(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL, *prefix;
	size_t len = 0, prefix_len;
	int line_is_valid, line_number = 1, i, num_instructions, valid_end = 0;
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
		line_is_valid = 0;
		for (i = 0; i < num_instructions; i++)
		{
			/* If the opcode starts with a known prefix, call the related function */
			prefix = instructions[i].opcode;
			prefix_len = strlen(prefix);
			if (strncmp(" ", &line[prefix_len], 1) == 0 || line[prefix_len] == '\0')
				valid_end = 1;
			if (strncmp(line, prefix, prefix_len) == 0 && valid_end)
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
	free(line);
	fclose(file);
	free_stack(stack);
}
