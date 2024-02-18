#include "sort.h"

/**
* merge - swap element and merge
* @array: the array
* @left: the left part
* @parition: the medium
* @right: the right part
*/
void merge(int *array, int left, int parition, int right)
{
	int i, j, k, n1 = parition - left + 1;
	int n2 = right - parition, *arr_l, *arr_r;

	arr_l = _calloc(n1, sizeof(int));
	arr_r = _calloc(n2, sizeof(int));
	if (arr_l == NULL || arr_r == NULL)
	{
		free(arr_l), free(arr_r);
		exit(EXIT_FAILURE);
	}
	/**copy the arr part*/
	for (i = 0; i < n1; i++)
		arr_l[i] = array[left + i];
	for (i = 0; i < n2; i++)
		arr_r[i] = array[parition + 1 + i];
	printf("[left]: ");
	print_array(arr_l, n1);
	printf("[right]: ");
	print_array(arr_r, n2);
	i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (arr_l[i] <= arr_r[j])
			array[k] = arr_l[i], i++;
		else
			array[k] = arr_r[j], j++;
		k++;
	}
	/**coping the remaining elements*/
	while (i < n1)
		array[k] = arr_l[i], i++, k++;
	while (j < n2)
		array[k] = arr_r[j], j++, k++;
	free(arr_l), free(arr_r);
	printf("[Done]: ");
	print_array(&array[left], i + j);
}
/**
* parition_part - partion the array
* @array: the array
* @left: the left part
* @right: the right part
*/
void parition_part(int *array, int left, int right)
{

	int partion;

	if (left < right)
	{
		partion = left + (right - left) / 2;

		parition_part(array, left, partion);
		parition_part(array, partion + 1, right);
		printf("Merging...\n");
		merge(array, left, partion, right);

	}

}
/**
* merge_sort - function that sorts an array of integers
* in ascending order using the Merge sort algorithm
* @array: the array
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{

	parition_part(array, 0, size - 1);

}

/**
 * *_calloc - function that allocates memory for an array, using malloc
 * Discription: creating calloc function , locate memory spaces
 * with initlize of 0 values not random values like malloc
 * @nmemb: number of array elements
 * @size:size of the array elements value
 * Return: pointer to the new located empty memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	int len;
	int i = 0;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	ptr = malloc(nmemb * size);/*WRONG*/

	if (ptr == NULL)
		return (NULL);

	len = nmemb * size;

	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}