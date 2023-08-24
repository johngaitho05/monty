#include "monty.h"

/**
 * set_arg - retrieve opcode argument from the environment variables
 * @arg: the variable on which to cast the argument
 * @command: the command being executed
 */
void set_arg(char *arg, char *command)
{
	int index = strlen(command);

	while (strchr(&monty_opcode[index], ' ') == 0)
		index++;
	strncpy(arg, monty_opcode + index, 1024);
	strip(arg, NULL);
}

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
