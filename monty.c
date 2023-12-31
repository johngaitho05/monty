#include "monty.h"

/**
 * main - the entry point for our monty program
 * @argc: number of args
 * @argv: array of string args
 * Return: 0 if successful else EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute(file);
	return (0);
}
