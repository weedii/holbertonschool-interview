#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: first grid
 * @grid1: second grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int unstable;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	do {
		unstable = 0;

		/* Check if the grid is unstable (any cell > 3) */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					unstable = 1;
					break;
				}
			}
			if (unstable)
				break;
		}

		if (unstable)
		{
			printf("=\n");
			print_grid(grid1);
		}

		int temp[3][3] = {0};

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					temp[i][j] -= 4;
					if (i > 0)
						temp[i - 1][j] += 1; /* Top */
					if (i < 2)
						temp[i + 1][j] += 1; /* Bottom */
					if (j > 0)
						temp[i][j - 1] += 1; /* Left */
					if (j < 2)
						temp[i][j + 1] += 1; /* Right */
				}
			}
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += temp[i][j];
			}
		}

  } while (unstable);
}
