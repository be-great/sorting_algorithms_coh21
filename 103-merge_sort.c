#include "sort.h"

/**
* merge - swap element and merge
* @array: the array
* @left: the left part
* @parition: the medium
* @right: the right part
* @arr_l_r: the array to mainplate
*/
void merge(int *array, int left, int parition, int right, int *arr_l_r)
{
	int i, j, k, n1 = parition - left + 1;
	int n2 = right - parition, *arr_l, *arr_r;

	arr_l = &arr_l_r[0];
	arr_r = &arr_l_r[n2];
	/**copy the arr part*/
	for (i = 0; i < n1; i++)
		arr_l[i] = array[left + i];
	for (i = 0; i < n2; i++)
		arr_r[i] = array[parition + 1 + i];
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
	printf("[left]: ");
	print_array(arr_l, i);
	printf("[right]: ");
	print_array(arr_r, j);
	printf("[Done]: ");
	print_array(&array[left], i + j);
}
/**
* parition_part - partion the array
* @array: the array
* @left: the left part
* @right: the right part
* @arr_l_r: the array to mainplate
*/
void parition_part(int *array, int left, int right, int *arr_l_r)
{

	int partion;

	if ((left + right) % 2 == 0)
		partion = ((left + right) / 2) - 1;
	else
		partion = (left + right) / 2;
	if (partion >= left)
	{
		parition_part(array, left, partion, arr_l_r);
		parition_part(array, partion + 1, right, arr_l_r);
		printf("Merging...\n");
		merge(array, left, partion, right, arr_l_r);

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
	int *arr_l_r;

	if (array == NULL || size < 2)
		return;

	arr_l_r = _calloc(size, sizeof(int));
	parition_part(array, 0, size - 1, arr_l_r);
	free(arr_l_r);
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

