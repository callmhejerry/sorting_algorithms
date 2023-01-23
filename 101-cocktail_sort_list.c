#include "sort.h"


int bubble_forward(listint_t **head, listint_t **front, listint_t **back);
int bubble_backward(listint_t **list, listint_t **front, listint_t **back);

/**
 * cocktail_sort_list - A function that sorts a doubly linked list
 * of intetgers in ascending order using the cocktail shaker algorithm
 * @list: the poinrter to the head of the doubly linkedlist
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *back, *front;
	int sorted;

	if (list == NULL || (*list)->next == NULL)
		return;

	back = *list;
	front = back->next;
	sorted = 0;

	while (sorted == 0)
	{
		sorted = bubble_forward(list, &front, &back);
		sorted = bubble_backward(list, &front, &back);
	}
}


/**
 * bubble_forward - A fucntion that sorts a doubly linked list
 * from left to right once using a bubble sort algorithm
 * @list: the pointer to the head of the list
 * @front: the pointer to the node that is ahead
 * @back: the pointer to the node that is at the back
 * Return: 1 if the list is already sorted, return 0 otherwise
 */
int bubble_forward(listint_t **list, listint_t **front, listint_t **back)
{
	int sorted;

	sorted = 1;
	while (*front != NULL)
	{
		if ((*front)->n < (*back)->n)
		{
			sorted = 0;
			/*detach front*/
			(*back)->next = (*front)->next;
			if ((*front)->next != NULL)
				((*front)->next)->prev = *back;
			if ((*back)->prev == NULL)
			{
				(*front)->prev = NULL;
				(*front)->next = *back;
				((*front)->next)->prev = *front;
				*list = *front;
			}
			else
			{
				(*front)->prev = (*back)->prev;
				(*front)->next = *back;
				((*front)->next)->prev = *front;
				((*front)->prev)->next = *front;
			}
			print_list(*list);
			if ((*back)->next == NULL)
				break;
			*front = (*back)->next;
		}
		else
		{
			*front = (*front)->next;
			*back = (*back)->next;
		}
	}
	if (*front == NULL)
		*front = (*back)->prev;
	return (sorted);
}

/**
 * bubble_backward - A function that sorts a doubly linkedlist of integers
 * from right to left using bubble sort algorithm
 * @list: the pointer to the head of the list
 * @front: the pointer to the node ahead
 * @back: the pointer to the node at the back
 * Return: 1 if the list is sorted, return 0 otherwise
 */
int bubble_backward(listint_t **list, listint_t **front, listint_t **back)
{
	int sorted;

	sorted = 1;

	while (*front != NULL)
	{
		if ((*back)->n < (*front)->n)
		{
			sorted = 0;
			/*detach back*/
			(*front)->next = (*back)->next;
			if ((*back)->next != NULL)
				((*back)->next)->prev = *front;

			if ((*front)->prev == NULL)
			{
				(*back)->prev = NULL;
				(*back)->next = *front;
				((*back)->next)->prev = *back;
				*list = *back;
			}
			else
			{
				(*back)->prev = (*front)->prev;
				(*back)->next = *front;
				((*back)->next)->prev = *back;
				((*back)->prev)->next = *back;
			}
			print_list(*list);
			if ((*back)->prev == NULL)
				break;
			*front = (*back)->prev;
		}
		else
		{
			*front  = (*front)->prev;
			*back = (*back)->prev;
		}
	}
	if (*front == NULL)
		*front = (*back)->next;
	return (sorted);
}
