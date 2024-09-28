#include "sort.h"

/**
 * max_array - Function to get the max value in the array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: The max value in the array.
 */
int max_array(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - Function to do counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @posDigit: The posDigit (1, 10, 100).
 */
void counting_sort(int *array, size_t size, int posDigit)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	if (output == NULL)
		return;

	for (size_t i = 0; i < size; i++)
		count[(array[i] / posDigit) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / posDigit) % 10] - 1] = array[i];
		count[(array[i] / posDigit) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Function that sorts an array using Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the max number to know the number of digits */
	int maxValue = max_array(array, size);

	/* Do counting sort for each digit */
	for (int x = 1; maxValue / x > 0; x *= 10)
		counting_sort(array, size, x);
}
