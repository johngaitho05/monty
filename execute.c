#include "monty.h"

char *opcode_arg;

/**
 * get_instructions - provides supported operations
 * Return: array of supported instructions
 */
instruction_t *get_instructions(void)
{
	static instruction_t instructions[] = {
			{"push", handle_push},
			{"pall", handle_pall},
			{"pint", handle_pint},
			{"pop", handle_pop},
			{"swap", handle_swap},
			{"add", handle_add},
			{"nop", handle_nop},
			{"sub", handle_sub},
			{"div", handle_div},
			{"mul", handle_mul},
			{"mod", handle_mod}
	};

	return (instructions);
}

/**
 * execute - executes the commands contained in the file
 * @file: the file containing monty bytes
 */
void execute(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL, *opcode;
	size_t len = 0;
	instruction_t *instructions = get_instructions();
	int is_valid, line_number = 1, i,

	num_instructions = _arraylen(&instructions);
	while (getline(&line, &len, file) != -1)
	{
		strip(line, NULL);
		line = remove_comment(line);
		if (strlen(line) == 0)
			continue;
		opcode = strtok(line, " ");
		opcode_arg = strtok(NULL, " ");
		is_valid = 0;
		for (i = 0; i < num_instructions; i++)
		{
			/* If the opcode starts with a known prefix, call the related function */
			if (opcode_match(opcode, instructions, i))
			{
				is_valid = 1;
				instructions[i].f(&stack, line_number);
			}
		}
		if (is_valid == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
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
