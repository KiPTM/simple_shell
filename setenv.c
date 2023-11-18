#include "shell.h"

/**
 * mysetenv - Initialize a new environment variable
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 */
void mysetenv(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Incorrect number of arguments\n", 30);
		/*return (1);*/
	}
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		write(2, "Failed to set environment variable\n", 35);
		/*return (1);*/
	}

	/*return (0);*/
}

/**
 * myunsetenv - Remove an environment variable
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 */
void myunsetenv(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Incorrect number of arguments\n", 30);
		/*return (1);*/
	}
	if (unsetenv(argv[1]) != 0)
	{
		write(2, "Failed to unset environment variable\n", 37);
		/*return (1);*/
	}

	/*return (0);*/
}
