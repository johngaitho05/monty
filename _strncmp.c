#include "monty.h"
#include <stddef.h>

/**
 * _strncmp - checks whether str1 starts with str2
 * @str1: the string
 * @str2: prefix
 * @n: number of bytes to compare
 * Return: 0 if successful else 'something else'
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
