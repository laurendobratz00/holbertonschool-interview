#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_palindrome - checks if singly linked list is a palindrome
 * @head: double pointer
 * Return: yes
 */

int is_palindrome(listint_t **head)
{
	if (*head == NULL)
		return (1);
	return (helper(head, *head));
}

/**
 * helper - helper function for palindrome
 * @left: double pointer
 * @right: single pointer
 * Return: 1 if palindrome, 0 if not
 */
int helper(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);
	if (helper(left, right->next) && (*left)->n == (right)->n)
	{
		*left = (*left)->next;
		return (1);
	}
	else
		return (0);
}