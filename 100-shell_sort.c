#include "sort.h"


/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the shell_sort algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (size < 2)
		return;

	while (gap <= (size - 1) / 3)
	{
		gap = gap * 3 + 1;
	}

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
