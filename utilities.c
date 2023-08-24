#include "monty.h"

/**
 * strip - remove specific characters at the beginning and end of string
 * @str: the string to strip
 * @tokens: characters to remove
 * Return: void (modifies input string in place)
 */
char  *strip(char *str, char *tokens)
{
	int length = strlen(str), i = 0;

	if (!tokens)
		tokens = " \n\t\r";

	if (length > 0)
	{
		/* Remove leading spaces **/
		while (i < length && strchr(tokens, str[i]))
			i++;
		memmove(str, str + i, length - i + 1);

		/* Remove trailing spaces */
		while (length > 0 && strchr(tokens, str[length - 1]))
		{
			str[length - 1] = '\0';
			length--;
		}
	}

	return (str);
}


/**
 * _arraylen - computes the size of a null-terminated array
 * @array: a nul-terminated array of strings
 * Return: number of elements in the array
 */
int _arraylen(instruction_t **array)
{
	int count  = 0;

	while (array[count] != NULL)
		count++;
	return (count);
}

/**
 * remove_comment - remove everything after #
 * @line: a string
 * Return: the line without comment
 */
char *remove_comment(char *line)
{
	size_t j = 0;

	while (j < strlen(line))
	{
		if (line[j] == '#')
		{
			line[j] = '\0';
			break;
		}
		j++;
	}
	return (line);
}

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
	if (strncmp(" ", &line[len], 1) == 0 || line[len] == '\0' || line[len] == '#')
		valid_end = 1;
	if (strncmp(line, prefix, len) == 0 && valid_end)
		return (1);
	return (0);
}

