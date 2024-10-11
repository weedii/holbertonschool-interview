#!/usr/bin/python3
"""Prime Game"""


def getPrimesArray(max_n):
    """Function to calculate prime numbers up to max_n"""

    # Assume all numbers are prime
    primes = [True] * (max_n + 1)
    primes[0] = primes[1] = False  # 0 and 1 not prime

    # Mark all multiples of prime n as non-prime
    for i in range(2, max_n + 1):
        if primes[i]:  # If i is true
            for multiple in range(i * 2, max_n + 1, i):
                primes[multiple] = False
    return primes


def isWinner(x, nums):
    """Prime Game determine the winner"""

    if not nums or x <= 0:
        return None

    maria_wins = 0
    ben_wins = 0

    primes = getPrimesArray(max(nums))

    for n in nums:
        prime_count = sum(primes[2 : n + 1])

        if prime_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
