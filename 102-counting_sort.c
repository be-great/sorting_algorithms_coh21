#include "sort.h"


/**
 * check_max - checks for the max value
 * @array: the array to check for max value
 * @size: the size of the array
 *
 * Return: the max value
*/

int check_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}



/**
 * counting_sort - a function that sorts an array of integers
 * in ascending order using the counting_sort algorithm
 *
 * @array: the array to sort using bubble sort
 * @size: the size of the array
 * Return: void
*/

void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max;
	int *count, *output;

	if (size < 2)
		return;

	max = check_max(array, size);

	/*initialize the count and ouput array*/
	count = malloc((max + 1) * sizeof(int));
	output = malloc(size * sizeof(int));

	for (j = 0; j <= max; j++)
	{
		count[j] = 0;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;

	print_array(count, max + 1);

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(count);
	free(output);
}
