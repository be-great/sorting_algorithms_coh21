#include "sort.h"


/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t swapped, i, j;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
