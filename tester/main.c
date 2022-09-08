#include "main.h"

char **commands = NULL;
char *line = NULL;
char *name_of_shell = NULL;
int status = 0;

/**
 * main - run the functions and prototypes
 *
 * @argc: count the number of arguments
 *
 * @argv: pointer to the address of the first argument string
 *
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **curr_command = NULL;
	size_t n = 0;
	int i, type_command = 0;

	signal(SIGINT, handler);
	name_of_shell = argv[0];
	while (1)
	{
		uniteractive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			curr_command = tokenizer(commands[i], " ");
			if (curr_command[0] == NULL)
			{
				free(curr_command);
				break;
			}
			type_command = parse_command(curr_command[0]);

			/* initializer -   */
			initializer(curr_command, type_command);
			free(curr_command);
		}
		free(commands);
	}
	free(line);

	return (status);
}
