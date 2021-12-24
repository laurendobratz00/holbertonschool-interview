#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mul - a program that multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 * Return: mul
 */

char *mul(char *num1, char *num2)
{
	int i = 0, j = 0, tmp;
	int l1 = strlen(num1);
	int l2 = strlen(num2);
	int a[100] = {0}, b[100] = {0};
	int ans[200] = {0};
	char *result = malloc(sizeof(int) * (strlen(num1) + strlen(num2)));

	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
	{
		a[j] = num1[i] - '0';
	}
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
	{
		b[j] = num2[i] - '0';
	}
	for (i = 0; i < l2; i++)
	{
		for (j = 0; j < l1; j++)
		{
			ans[i + j] += b[i] * a[j];
		}
	}
	for (i = 0; i < l1 + l2; i++)
	{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
	}
	for (i = l1 + l2; i >= 0; i--)
	{
		if (ans[i] > 0)
		break;
	}
	for (j = i; j >= 0; j--)
	{
		result[i - j] = (char)('0' + ans[j]);
	}
	return (result);
}

/**
 * main - driver code
 * @argc: argc char
 * @argv: char double pointer
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (strlen(num1) == 0 || strlen(num2) == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	result = mul(num1, num2);
	free(result);
	return (0);
}
