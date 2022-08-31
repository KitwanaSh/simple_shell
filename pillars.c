#include "main.h"

/**
 *_strtok - A string to make token
 *@_str: string to be tokened
 *@delim: delimiter to be used to make a string tokened
 *@save_ptr: Tuning the following token
 *
 *Return: The following token
 */
char *_strtok(char *_str, char *delim, char **save_ptr)
{
	char *terminate;

	if (_str == NULL)
		_str = *save_ptr;

	if (*_str == '\0')
	{
		*save_ptr = _str;
		return (NULL);
	}

	_str += _strspn(_str, delim);
	if (*_str == '\0')
	{
		*save_ptr = _str;
		return (NULL);
	}

	terminate = _str + _strcspn(_str, delim);
	if (*terminate == '\0')
	{
		*save_ptr = terminate;
		return (_str);
	}

	*terminate = '\0';
	*save_ptr = finish + 1;
	return (_str);
}

/**
 * _atoi - changes a string as int
 * @t: the text string to be changed
 *
 * Return: The made int
 */
int _atoi(char *t)
{
	unsigned int y = 0;

	do {
		if (*t == '-')
			return (-1);
		else if ((*t < '0' || *t > '9') && *t != '\0')
			return (-1);
		else if (*t >= '0'  && *t <= '9')
			y = (y * 10) + (*y - '0');
		else if (y > 0)
			break;
	} while (*t++);
	return (y);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: Pointer to the address of new memory or (NULL) for fail
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		temp = malloc(new_size);
		return (temp);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp = malloc(new_size);
		if (temp != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp + i) = *((char *)ptr + i);
			free(ptr);
			return (temp);
		}
		else
			return (NULL);

	}
}

/**
 * handler - handles the signal raised by CTRL-C
 * @sign_um: signal number
 *
 * Return: void
 */
void handler(int sign_num)
{
	if (sign_num == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * remove_comment - removes/ignores everything after a '#' char
 * @input: Used input
 *
 * Return: Nothing
 */
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
