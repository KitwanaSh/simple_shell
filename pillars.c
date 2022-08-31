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

/**
 * _strchr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

/**
 * _strspn -finds the length of a prefix substring
 * @s1: looked string
 * @s2: utilized string
 *
 * Return: Number of bytes in a segment
 */

int _strspn(char *s1, char *s2)
{
	int i = 0;
	int corr = 0;

	while (s1[i] != '\0')
	{
		if (_strchr(s2, s1[i]) == NULL)
			break;
		corr++;
		i++;
	}
	return (corr);
}

/**
 * _strcat - concatenates two strings
 * @meeting: string to be concatenated to
 * @prep: concatitate string
 *
 * Return: new string
 */

char *_strcat(char *meeting, char *prep)
{
	char *n_string =  NULL;
	int len_meet = _strlen(meeting);
	int len_prep = _strlen(prep);

	n_string = malloc(sizeof(*n_string) * (len_meet + len_prep + 1));
	_strcpy(meeting, n_string);
	_strcpy(prep, n_string + len_prep);
	_string[len_meet + len_prep] = '\0';
	return (n_string);
}

/**
 * _strcspn - computes segment of str1 which consists of characters not in str2
 * @s1: looked string
 * @s2: utilized string
 *
 * Return: length of strings
 */


int _strcspn(char *s1, char *s2)
{
	int len = 0, i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (_strchr(s2, s1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}


/**
 * tokenizer - Make token the entry to make it a string list
 * @ent_str: parsed entry
 * @delim: delimiter in tring dat type
 *
 * Return: A token list
 */

char **tokenizer(char *input_str, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(ent_str, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}
	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}
