#include "sort.h"
#include <stdint.h>
/**
* getMax - Gets the maximum element from an array
*
* @array: The array to find the maximum from
* @size: Size of the array
* Return: The maximum element
*/
int getMax(int *array, size_t size)
{

	int max = array[0];

	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);

}
/**
* countingSort - Perform counting sort on the specified significant digit
*
* @array: The array to be sorted
* @size: Size of the array
* @exp: The current significant digit
*/
void countingSort(int *array, size_t size, int exp)
{
	size_t base = 10;

	int *count, *output;

	size_t i;

	count = malloc(sizeof(int) * base);
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		exit(EXIT_FAILURE);
	}
	/*init base array with 0*/
	for (i = 0; i < base; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % base]++;

	for (i = 1; i < base; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count), free(output);

}

/**
* radix_sort -  function that sorts an array of
* integers in ascending order using the Radix sort algorithm
* @array: the array
* @size: the size of the array
*/

void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (array && size >= 2)
	{
		max = getMax(array, size);
		for (exp = 1; max / exp > 0; exp *= 10)
		{
			countingSort(array, size, exp);
			print_array(array, size);
		}
	}
}
