#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two halves of the array
 * @array: array
 * @left: left half start index
 * @mid: middle index
 * @right: right half end index
 * @temp: temp array for merging
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts array using merge sort
 * @array: array to be sorted
 * @left: starting index
 * @right: ending index
 * @temp: temp array for merging
 */
void merge_sort_recursive(int *array, int left, int right, int *temp)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		/* Sort first and second halves */
		merge_sort_recursive(array, left, mid, temp);
		merge_sort_recursive(array, mid + 1, right, temp);

		/* Merge the sorted halves */
		merge(array, left, mid, right, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, 0, size - 1, temp);

	free(temp);
}
