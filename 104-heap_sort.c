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
 * sift_down - a function for handling the sift_down implementation
 * @array: the array
 * @size: the size of the array
 * @i: the index
*/
void sift_down(int *array, size_t size, int i)
{
	int biggest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[biggest])
		biggest = left;

	if (right < size && array[right] > array[biggest])
		biggest = right;

	if (biggest != i)
	{
		swap(&array[i], &array[biggest]);
		sift_down(array, size, biggest);
	}
}



/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the heap_sort algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/

void heap_sort(int *array, size_t size)
{
	int i;

	/*Build the heap max*/
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i);
	}

	/*Extract elements and build the max again*/
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}
