#!/usr/bin/python3

"""
Get the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid
    """

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # top (i - 1)
                if grid[i - 1][j] == 0:
                    perimeter += 1

                # bottom (i + 1)
                if grid[i + 1][j] == 0:
                    perimeter += 1

                # left (j - 1)
                if grid[i][j - 1] == 0:
                    perimeter += 1

                # right (j + 1)
                if grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
