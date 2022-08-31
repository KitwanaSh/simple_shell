#include "main.h"

/**
 *env - Prints the current environnement
 * @command_tokened: command entered
 *
 * Return: Nothing at all
 */

void env(char **command_tokened)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - To quit the shell prompt
 * @command_tokened: the entered command
 *
 * Return: Nothing
 */
void (char **command_tokened)
{
	int number_token = 0, arg;

	for (; commad_tokened[number_token] != NULL; number_token++)
		;
	if (number_token == 1)
	{
		free(command_tokened);
		free(line);
		free(commands);
		exit(status);
	}
	else if (number_token == 2)
	{
		agr = _atoi(command_tokened[1]);
		if (arg == -1)
		{
			printf(name_of_shell, STRERR_FILENO);
			printf(": 1: Exit uncommited number: ", STDERR_FILENO);
			printf(command_tokened[1], STDERR_FILENO);
			printf("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(command_tokened);
			free(line);
			free(commands);
			exit(arg);
		}
	}
	else
	{
		printf("$: Exit does not take many arguments\n", STDERR_FILENO);
	}
}
