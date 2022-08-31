#include "main.h"

/*
 *void interactive takes in void and return void
 * char **curr_command is assigned null
 * size_t n  is assigned 0
 * int i and type_command is assigned 0
 * free(line)
 * exit(status)
 */

void uninteractive(void)
{
	char **curr_command = NULL;
	size_t n = 0;
	int i, type_command = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
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
				initializer(curr_command, type_command);
				free(curr_command);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
