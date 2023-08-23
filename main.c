#include "monty.h"

/**
 * main - the entry point for our monty program
 * @argc: number of args
 * @argv: array of string args
 * @env: environment variables
 * Return: 0 if successful else EXIT_FAILURE
 */
int main(int argc, char *argv[], char **env)
{
	FILE *file;

	(void)env;
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
	execute(file, env);
	return (0);
}
