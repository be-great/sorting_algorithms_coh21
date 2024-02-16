#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* create_listint - Creates a doubly linked list from an array of integers
*
* @array: Array to convert to a doubly linked list
* @size: Size of the array
*
* Return: Pointer to the first element of the created list. NULL on failure
*/
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
	listint_t *list;
	int array[] = {48, 99, 71};

	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	list = NULL;

	/**Case 1*/
	printf("Case 1\n");
	int array0[] = {24,25};

	n = sizeof(array0) / sizeof(array0[0]);

	list = create_listint(array0, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	list = NULL;
	/**Case 2*/
	printf("Case 2\n");
	int array1[] = {};

	n = sizeof(array1) / sizeof(array1[0]);

	list = create_listint(array1, n);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	/**Case 3*/
	printf("Case 3\n");
	int array2[] = {24,12,12, 1};

	n = sizeof(array2) / sizeof(array2[0]);

	list = create_listint(array2, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
