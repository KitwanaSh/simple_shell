#include "main.h"

/*
 * void initializer takes in pointer to pointer and an integer
 *
 * @ pointer
 *
 * pid_t mypid calls the function **curr_command
 *
 * return void
 */

void initializer(char **curr_command, int type_command)
{
	pid_t mypid;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		mypid = fork();
		if (mypid == 0)
		{
			execute_command(curr_command, type_command);
		}
		else
		{
			waitpid(mypid, &status, 0);
			status >>= 0;
		}
	}
	else
		execute_command(curr_command, type_command);
}
