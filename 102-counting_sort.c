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
	size_t i, max;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	max = check_max(array, size);

	/*initialize the count and ouput array*/
	count = malloc((max + 1) * sizeof(int));
	output = malloc(size * sizeof(int));

	if (output == NULL || count == NULL)
		return;

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
