#include "shell.h"

/**
 * allocate_path- Function allocate path accordingly
 * @cmd: The pointer to the command
 * Return: The  right path for the command
 */
char *allocate_path(const char *cmd)
{
	char *pathTokens = NULL;
	char *created_path = NULL;
	struct stat buffer;

	if (getenv("PATH"))
	{
		pathTokens = strtok(getenv("PATH"), ":");
		while (pathTokens != NULL)
		{
			created_path = malloc(strlen(pathTokens) + strlen(cmd) + 2);
			if (created_path != NULL)
			{
				strcpy(created_path, pathTokens);
				strcat(created_path, "/");
				strcat(created_path, cmd);
				if (stat(created_path, &buffer) == 0)
				{
					return (created_path);
				}
				free(created_path);
				created_path = NULL;
				pathTokens = strtok(NULL, ":");
			} else
			{
				exit(EXIT_FAILURE);
			}
		}
		if (stat(cmd, &buffer) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	return (NULL);
}
