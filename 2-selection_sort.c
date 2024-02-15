#include "sort.h"


/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the selection sort algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
			{
				minimum = j;
			}
		}

		if (minimum != i)
		{
			temp = array[i];
			array[i] = array[minimum];
			array[minimum] = temp;
			print_array(array, size);
		}
	}
}
