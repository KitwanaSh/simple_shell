#include "main.h"

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
 * tokenizer - make token the entry to make it a string list
 * @ent_str: parsed entry
 * @delim: delimiter in tring dat type
 *
 * Return: A token list
 */

char **tokenizer(char *ent_str, char *delim)
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
