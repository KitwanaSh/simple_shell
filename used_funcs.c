#include "main.h"

/**
 * parse_command - determines the type of the command
 * @command: The pased command
 *
 * Return: constant variable that represets
 * Description - This is where the external commands comme in handy
 */

int parse_command(char *command)
{
	int i;
	char *path = NULL;
	char *intern_command[] = {"env", "exit", NULL};

	for (i = 0; command[i] != "\0"; i++)
	{
		if (command[i] == "/")
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; intern_command[i] != NULL; i++)
	{
		if (_strcmp(command, intern_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * execute_command - executes a command based on it's type
 * @command_tokened: the command to be tokened as (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: Nothing
 */
void execute_command(char **command_tokened, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(command_tokened[0], command_tokened, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(command_tokened[0]), command_tokened, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(command_tokened[0]);
		func(command_tokened);
	}
	if (command_type == INVALID_COMMAND)
	{
		print(name_of_shell, STDERR_FILENO);
		print("-> 1: ", STDERR_FILENO);
		print(command_tokened[0], STDERR_FILENO);
		print("(: Not Found!\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * get_func - gets the function
 * @command: the entered command
 *
 * Return: Nothing
 */
void (*get_func(char *command))(char **)
{
	int i;
	func_org org_sing[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, org_sing[i].name_of_command) == 0)
			return (org_sing[i].func);
	}
	return (NULL);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: variable  value of success or NULL if fails
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *gather_t;
	char *copy_name;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (gather_t = *my_environ, copy_name = name;
		     *gather == *copy_name; gather++, copy_name++)
		{
			if (*gather == '=')
				break;
		}
		if ((*gather == '=') && (*copy_name == '\0'))
			return (gather + 1);
	}
	return (NULL);
}
