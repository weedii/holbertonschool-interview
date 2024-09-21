#!/usr/bin/python3
"""rain"""


def rain(walls):
    """rain"""

    lenWalls = len(walls)

    result = 0

    for i in range(1, lenWalls - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, lenWalls):
            right = max(right, walls[j])

        result = result + (min(left, right) - walls[i])

    return result