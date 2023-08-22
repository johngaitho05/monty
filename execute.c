#include "main.h"

int opcode_arg;

/**
 * execute - executes the commands contained in the file
 * @file: the file containing monty bytes
 */
void execute(FILE *file)
{
	stack_t *stack = NULL;
	char line[1024], opcode[50], *prefix;
	int line_is_valid, line_number = 1;
	instruction_t instructions[] = {{"push", handle_push},
			{"pop", handle_pop}, {"pall", handle_pall},
			{"pint", handle_pint}
	};
	size_t i, len, num_instructions = sizeof(instructions)
			/ sizeof(instructions[0]);
	/* Read the file line by line and execute each command */
	while (fgets(line, sizeof(line), file))
	{
		len = strlen(line);
		/* Remove trailing whitespaces and new line characters */
		while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
			line[--len] = '\0';
		if (strlen(line) == 0)
			continue;
		/* TODO: handle this correctly using atoi */
		if (sscanf(line, "%49s %d", opcode, &opcode_arg) < 2)
			opcode_arg = 0;
		line_is_valid = 0;
		for (i = 0; i < num_instructions; i++)
		{
			/* If the opcode starts with a known prefix, call the related function */
			prefix = instructions[i].opcode;
			if (strncmp(opcode, prefix, strlen(prefix)) == 0)
			{
				line_is_valid = 1;
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (line_is_valid == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
}
