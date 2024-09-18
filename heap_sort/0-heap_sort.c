#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - Maintains the max-heap
 * @array: The array of integers
 * @size: Size of the array
 * @i: The index to heapify
 * @n: The size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: The array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (size_t i = size / 2 - 1; i < size; i--)
		heapify(array, size, i, size);

	for (size_t i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
