#include "main.h"

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
