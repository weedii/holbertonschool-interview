#!/usr/bin/python3
"""
Get the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    blaaa blaaa
    """

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if grid[i - 1][j] == 0:
                    perimeter += 1

                if grid[i + 1][j] == 0:
                    perimeter += 1

                if grid[i][j - 1] == 0:
                    perimeter += 1

                if grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
