#include "monty.h"

/**
 * _memmove -copies a block of memory
 * @dest: where to copy to
 * @src: where to copy from
 * @n: number of bytes to copy
 * Return: pointer to the copied memory block
 */
void *_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;

	if (d < s)
	{
		for (i = 0; i < n; i++)
		{
			d[i] = s[i];
		}
	}
	else if (d > s)
	{
		for (i = n; i > 0; i--)
		{
			d[i - 1] = s[i - 1];
		}
	}

	return (dest);
}
