#!/usr/bin/python3

"""
determine the fewest number of coins needed to meet a given amount total
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins needed to meet a given amount total
    """

    if total <= 0:
        return 0

    if len(coins) <= 0:
        return -1

    if total in coins:
        return 1

    tmpArr = [0] * (total + 1)

    for i in range(1, total + 1):
        tmpArr[i] = total + 1

    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                tmpArr[i] = min(tmpArr[i], 1 + tmpArr[i - coin])
    return tmpArr[total] if tmpArr[total] != total + 1 else -1
