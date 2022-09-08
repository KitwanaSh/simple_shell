#include "main.h"

/**
 *env - Prints the current environnement
 * @command_tokened: command entered
 *
 * Return: Nothing at all
 */

void env(char **command_tokened __attribute__((unused)))
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
void quit(char **command_tokened)
{
	int number_token = 0, arg;

	for (; command_tokened[number_token] != NULL; number_token++)
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
		arg = _atoi(command_tokened[1]);
		if (arg == -1)
		{
			print(name_of_shell, STDERR_FILENO);
			print(": 1: Exit: uncommited number: ", STDERR_FILENO);
			print(command_tokened[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
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
		print("$: Exit does not take many arguments\n", STDERR_FILENO);
	}
}
