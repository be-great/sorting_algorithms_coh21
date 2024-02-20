#include <stdio.h>
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
* bitonic_merge - Performs a bitonic merge on the given array
*
* @array: The array to be merged
* @low: the left part of the array
* @size: Size of the array
* @dir: Sorting direction (1 for ascending, 0 for descending)
*/
void bitonic_merge(int *array, int low, size_t size, int dir)
{
	if (size > 1)
	{
		size_t k = size / 2;
		size_t i;

		for (i = low; i < k + low; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				/*Swap elements if they are in the wrong order*/
				swap(&array[i], &array[i + k]);
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);

	}
}

/**
* bitonic_sort_recursive - Recursively applies bitonic sort
*
* @array: The array to be sorted
* @low: the left part of the array
* @size: Size of the array
* @dir: Sorting direction (1 for ascending, 0 for descending)
* @fullsize: the original size of the original array
*/
void bitonic_sort_recursive(int *array, int low, size_t size, int dir,

			size_t fullsize)
{
	if (size > 1)
	{
		size_t k = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, fullsize,
				(dir == 1) ? "UP" : "DOWN");
		print_array(array + low, size);

		bitonic_sort_recursive(array, low, k, 1, fullsize);
		bitonic_sort_recursive(array, low + k, k, 0, fullsize);

		bitonic_merge(array, low, size, dir);
		printf("Result [%lu/%lu] (%s):\n", size, fullsize,
				(dir == 1) ? "UP" : "DOWN");
		print_array(array + low, size);

	}
}

/**
* bitonic_sort - Sorts an array of integers in ascending order using
*                the Bitonic sort algorithm
*
* @array: The array to be sorted
* @size: Size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	if (array && size >= 2)
	{
		bitonic_sort_recursive(array, 0, size, 1, size);
	}
}
