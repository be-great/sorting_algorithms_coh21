#include "sort.h"

/**
* swap_nodes - function that swap two node
* insertion_sort_list - sorts a doubly linked list in ascending order
* @list: the headder
* using the Insertion sort algorithm
* @a: node 1
* @list: double pointer to the head of the list
* @b: node 1
*/

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	if (!b->prev)
		*list = b;
}


/**
* cocktail_sort_list - function that sorts a doubly linked list of
* integers in ascending order
* using the Cocktail shaker sort algorithm
* @list: the list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		/* Traverse from left to right: Forward */
		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				/* Print the list after each swap */
				print_list(*list);
			}
			else
				start = start->next;
		}
		if (!swapped)
			break;
		end = start;
		/* Traverse from right to left: Backward */
		while (start && start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->prev;
		}
	}
}
