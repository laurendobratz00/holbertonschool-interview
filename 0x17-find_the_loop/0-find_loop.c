#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 * @head: head of the linked list
 * Return: address of node where the loop starts, NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	struct listint_s *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			/* Return 1 to indicate that loop is found */
			return (head);
		}
	}
	/* Return NULL to indicate that there is no loop */
	return (NULL);
}
