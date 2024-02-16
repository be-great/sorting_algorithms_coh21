#include "sort.h"

/**
* swap_nodes - function that swap two node
* @list: the headder
* @node0: node 1
* @node1: node 1
*/
void swap_nodes(listint_t **list, listint_t **node0, listint_t **node1)
{
	listint_t *prev_one, *prev_two;
	listint_t *next_one, *next_two;
	int yes = 0;

	if (*list == *node0)
		yes = 1;
	prev_one = *node1;
	prev_two = (*node0)->prev;
	next_one = (*node1)->next;
	next_two = *node0;

	/*swap here*/
	(*node0)->prev = prev_one;
	(*node0)->next = next_one;
	(*node1)->prev = prev_two;
	(*node1)->next = next_two;
	/*update the chaining*/
	if (prev_two != NULL && next_one != NULL)
	{
		prev_two->next = *node1;
		next_one->prev = *node0;
	}
	else if (prev_two != NULL)
	{
		prev_two->next = *node1;
	}
	else
	{
	next_one->prev = *node0;
	}
	/*update the head if node0 was the head*/
	if (yes == 1)
		*list = *node1;

}

/**
* insertion_sort_list - sort value of node using insertion algorithm
* @list: the double linkind list
*/

void insertion_sort_list(listint_t **list)
{

	listint_t *current, *prev, *temp, *next;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL || (*list)->next->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{

		temp = current;
		next = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > temp->n)
		{
			swap_nodes(list, &prev, &temp);
			prev = temp->prev;
			print_list(*list);
		}

		current = next;
	}


}
