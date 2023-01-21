#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * integers in ascending order using the insertion sort algorithm
 * @list: A pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *now, *next;

	now = *list;
	if (now != NULL && now->next != NULL)
	{
		prev = now->prev, next = now->next;
		while (now != NULL)
		{
			if (prev != NULL && now->n < prev->n)
			{
				while (prev != NULL && now->n < prev->n)
				{
					prev->next = now->next;
					if (now->next != NULL)
						now->next->prev = prev;
					now->prev = NULL;
					now->next = prev;
					if (prev->prev == NULL)
					{
						prev->prev = now;
						*list = now;
					}
					else
					{
						now->prev = prev->prev;
						now->next->prev = now;
						now->prev->next = now;
					}
					print_list(*list);
					prev = now->prev;
				}
			}
			now = next;
			if (now != NULL)
				prev = now->prev;
			if (next != NULL)
				next = next->next;
		}
	}
}
