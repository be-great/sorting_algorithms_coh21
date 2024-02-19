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
 * @root: the root index of the array
 * @heap_size: the size of the heap
*/
void sift_down(int *array, size_t size, int root, size_t heap_size)
{
	int biggest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < heap_size && array[left] > array[biggest])
		biggest = left;

	if (right < heap_size && array[right] > array[biggest])
		biggest = right;

	if (biggest != root)
	{
		swap(&array[root], &array[biggest]);
		print_array(array, size);
		sift_down(array, size, biggest, heap_size);
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

	if (array == NULL || size < 2)
		return;

	/*Build the heap max*/
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i, size);
	}

	/*Extract elements and build the heap max again*/
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
