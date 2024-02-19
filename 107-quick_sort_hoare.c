#include "sort.h"

/**
* swap - Swaps two integers.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}


/**
 * Hoare_partition_scheme - a function to implement the hoare partition
 * @array: the array to work on
 * @size: the size of the array
 * @start: the beginning of the array
 * @end: the end of the array
 * Return: the partiioned
*/
int Hoare_partition_scheme(int *array, size_t size, int start, int end)
{
	int pivot = array[start];
	int i, j;

	for (i = end - 1, j = start + 1; i > j;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	return (i);
}


/**
 * quickSort - a function to implement the quickSort
 * @array: the array to work on
 * @size: the size of the array
 * @start: the beginning of the array
 * @end: the end of the array
*/

void quickSort(int *array, size_t size, int start, int end)
{
	if (start < end)
	{
		int pi = Hoare_partition_scheme(array, size, start, end);

		quickSort(array, size, start, pi - 1);
		quickSort(array, size, pi, end);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * in ascending order using the quick_sort_hoare algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/


void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, size, 0, size - 1);
}
