#include "sort.h"
/**
 * switch_back - switch the given index backword one step
 * @list: pointer to current head of list
 * @point: array element to be switched
 * Return: returns nothing
 */
void switch_back(listint_t **list, listint_t *point)
{
	listint_t *front, *back;

	front = point;
	back = point->prev;

	back->next = front->next;

	front->next = back;
	front->prev = back->prev;
	back->prev = front;
	if (front->prev)
		front->prev->next = front;
	else
	{
		*list = front;
		/*since front does not have prev. it becomes the head*/
	}

	if (back->next)
		back->next->prev = back;
}

/**
* sort_backwards - searches array backwards to find unsorted items
* @array: pointer containing current head of list
* @point: point to start backwards search
* Return: returns nothing
*/
void sort_backwards(listint_t **array, listint_t *point)
{
	listint_t *head;

	head = point;
	while (head->prev)
	{
		if (head->prev->n > head->n)
		{
			switch_back(array, head);
			print_list(*array);
		}
		else
			head = head->prev;
	}
}

/**
 * insertion_sort_list - sort linked list using insertion method
 * @list: pointer to the head of linked list
 * Return: returns nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head;

	if (!list)
		return;
	if (!*list)
		return;

	head = *list;

	while (head)
	{
		if (head->prev)
		{
			if (head->n < head->prev->n)
			{
				switch_back(list, head);
				print_list(*list);
				sort_backwards(list, head);
			}
		}
		head = head->next;

	}
}
