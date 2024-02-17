#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int array0[] = {1, 2, 3, 4};
    int array1[] = {1, 2, 3, 4, 5};
	size_t n = sizeof(array) / sizeof(array[0]);
    size_t n0 = sizeof(array0) / sizeof(array0[0]);
    size_t n1 = sizeof(array1) / sizeof(array1[0]);
	print_array(array, n);
	printf("\n");
	merge_sort(array, n);
	printf("\n");
	print_array(array, n);
    printf("-----------------------\n");
    print_array(array0, n0);
	printf("\n");
	merge_sort(array0, n0);
	printf("\n");
	print_array(array0, n0);
    printf("-----------------------\n");
    print_array(array1, n1);
	printf("\n");
	merge_sort(array1, n1);
	printf("\n");
	print_array(array1, n1);
	return (0);
}
