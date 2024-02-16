#include "sort.h"

/**
* swap_node - swap a node for its previous one
* @node: node to be swapped
* @list: pointer to the head of the list
* Return: pointer to the new position of the swapped node
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
* insertion_sort_list - sorts a doubly linked list in ascending order
* using the Insertion sort algorithm
* @list: double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
