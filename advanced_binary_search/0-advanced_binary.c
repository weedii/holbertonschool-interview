#include "search_algos.h"

/**
 * print_array - Prints the array
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_binary - Recursively searches for the first occurrence of value
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: Value to search for
 * Return: Index where the value is located or -1
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (recursive_binary(array, left, mid, value));
	} else if (array[mid] > value)
		return (recursive_binary(array, left, mid, value));
	else
		return (recursive_binary(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a sorted
 * array
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index where the value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
