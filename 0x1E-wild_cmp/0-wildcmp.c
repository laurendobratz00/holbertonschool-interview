#include "holberton.h"

/**
 * wildcmp - compares two strings to see if they are identical or not
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if identical, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
	int flag = 0, i = 0;

	if ((*s1 == '\0' && *s2 == '\0') || *s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s2[i] == '*')
		{
			return (1);
		}
		if (s1[i] != s2[i])
		{
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
