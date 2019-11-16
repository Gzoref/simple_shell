#include "shell.h"

/**
 * _getchar - Gets a character
 *
 * Return: Character
 */

int _getchar(void)
{
	char buffer[BUFFERSIZE];
	char *buff = buffer;
	int index = 0;

	if (index == 0)
	{
		index = read(0, buffer, 1);
	}
	if (index-- >= 0)
	{
		return (*buff++);
	}
	return (EOF);
}


/**
 * _atoi - Convert a string to an integer.
 *
 * @s: input string
 *
 * Return: integer
 */

int  _atoi(char *s)
{
	int sign, result, index;

	result = 0;
	sign = 0;

	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] == '-')
		{
			sign++;
		}
		if (s[index] > 47 && s[index] < 58)
		{
			while (s[index] > 47 && s[index] < 58)

				result = result * 10 - (s[index++] - 48);
				break;
		}
	}
	return (result *= sign % 2 == 0 ? -1 : 1);
}


/**
 * word_counter - Counts words
 *
 * @str: char pointer
 *
 * Return: Integer
 */


int word_counter(char *str)
{
	int count1, count2 = 0;

	for (count1 = 0; str[count1] != '\0'; count1++)
	{
		if (str[count1] != ' ' && (str[count1 + 1] == ' ' || str[count1 + 1] == '\0'))
		{
			count2++;
		}
	}
	return (count1);
}
