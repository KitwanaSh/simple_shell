#include "main.h"
 
/**
 * print - the printing function
 * @string to stdout
 * @string: string to be printed
 * @str_go: stream to print out to
 *
 * Return: Nothing
 */
void print(char *string, int str_go)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(str_go, &string[i], 1);
}

/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: Nothing
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 * _strcpy - copies a string to another buffer
 * @prep: source to copy from
 * @meet: destination to copy to
 *
 * Return: Nothing
 */

void _strcpy(char *prep, char *meet)
{
	int i = 0;

	for (; prep[i] != '\0'; i++)
		meet[i] = prep[i];
	prep[i] = '\0';
}

/**
 * _strlen - counts string length
 * @string: string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcmp - compare two strings
 * @str_1: first string to be compared
 * @sstr_2: second string to be compared
 *
 * Return: result of two string
 */

int _strcmp(char *str_1, char *str_2)
{
	int i = 0;
	while (str_1[i] != '\0')
	{
		if (str_1[i] != str_2[i])
			break;
		i++;
	}
	return (str_1[i] - str_2[i]);
}
