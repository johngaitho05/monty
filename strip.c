#include "monty.h"


/**
 * strip - remove specific characters at the beginning and end of string
 * @str: the string to strip
 * @tokens: characters to remove
 * Return: void (modifies input string in place)
 */
char  *strip(char *str, char *tokens)
{
	int length = _strlen(str), i = 0;

	if (!tokens)
		tokens = " \n\t\r";

	if (length > 0)
	{
		/* Remove leading spaces **/
		while (i < length && _strchr(tokens, str[i]))
			i++;
		_memmove(str, str + i, length - i + 1);

		/* Remove trailing spaces */
		while (length > 0 && _strchr(tokens, str[length - 1]))
		{
			str[length - 1] = '\0';
			length--;
		}
	}

	return (str);
}
