#include "monty.h"

/**
 * setenv - sets an environment variable
 * @env: pointer to the environment variables
 * @name: name fo the variable being added
 * @value: the value of the variable
 * @overwrite: whether the variable should be overwritten if it exists
 * Return: 0 if successful else -1
 */
int setenv(char ***env, const char *name, const char *value, int overwrite)
{
	char *env_entry = NULL, **environ = *env;
	size_t env_entry_len = 0;
	int i;

	if (!name || !value || strchr(name, '=') || strchr(value, '='))
	{
		return (-1); /* Invalid input */
	}

	/* Check if the environment variable already exists */
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) ==
		0 && environ[i][strlen(name)] == '=')
		{
			if (!overwrite)
				return (0); /* Variable exists and overwrite is not allowed */
			env_entry = environ[i];
			env_entry_len = strlen(env_entry);
			break;
		}
	}

	/* Create a new environment variable entry */
	if (env_entry == NULL)
	{
		/* +2 for '=' and null terminator */
		env_entry_len = strlen(name) + strlen(value) + 2;
		env_entry = (char *)malloc(env_entry_len);
		if (env_entry == NULL)
		{
			return (-1); /* Memory allocation failure */
		}
		environ[i] = env_entry;
	}

	sprintf(env_entry, "%s=%s", name, value);

	return (0);
}
