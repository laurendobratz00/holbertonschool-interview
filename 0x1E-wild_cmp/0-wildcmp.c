#include "holberton.h"

/**
 * wildcmp - compares two strings to see if they are identical or not
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if identical, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
	int c;

	c = compare(s1, s2);
	if (c == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * compare - compares two strings
 * @a: string 1
 * @b: string 2
 * Return: 1 if indentical, 0 if not
 */

int compare(char a[], char b[])
{
	int flag = 0, i = 0;

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
