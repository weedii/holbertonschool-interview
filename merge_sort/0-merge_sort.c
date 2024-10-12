#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two halves of the array
 * @array: array
 * @left: left half
 * @mid: array mid
 * @right: right half
 */
void merge(int *array, int left, int mid, int right)
{
	int n1 = mid - left + 1, n2 = right - mid; /* left & right half size */
	int *L = malloc(n1 * sizeof(int)), *R = malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];
	printf("Merging...\n[left]: ");
	print_array(L, n1);
	printf("[right]: ");
	print_array(R, n2);
	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		} else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++, k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
	free(L), free(R);
}


/**
 * merge_sort_recursive - merge sort recursive
 * @array: array
 * @left: left half
 * @right: right half
 */
void merge_sort_recursive(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge_sort_recursive(array, 0, size - 1);
}
