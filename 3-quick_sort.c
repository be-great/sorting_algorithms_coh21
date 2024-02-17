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
* lomuto_partition - Lomuto partition scheme for Quick Sort.
* @array: Array to be partitioned.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Size of the array.
* Return: Index of the pivot after partitioning.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	i++;
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
* quick_sort_helper - Recursive helper function for Quick Sort.
* @array: Array to be sorted.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Size of the array.
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort.
* @array: Array to be sorted.
* @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}


	quick_sort_helper(array, 0, size - 1, size);
}
