#include "slide_line.h"

/**
 * slide_left - Slides and merges the line to the left.
 * @line: Array of integers.
 * @size: Size of the array.
 */
void slide_left(int *line, size_t size)
{
	size_t i, j;

	/* Slide non-zero values to the left */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}

	/* Merge values if they are the same */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Slide again after merging */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * slide_right - Slides and merges the line to the right.
 * @line: Array of integers.
 * @size: Size of the array.
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	/* Slide non-zero values to the right */
	for (i = size - 1, j = size - 1; (int)i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}

	/* Merge values if they are the same */
	for (i = size - 1; (int)i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Slide again after merging */
	for (i = size - 1, j = size - 1; (int)i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Pointer to the array of integers.
 * @size: Size of the array.
 * @direction: Direction to slide and merge.
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);

	return (1);
}
