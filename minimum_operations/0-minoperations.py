#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """minOperations function"""
    count = 0
    string = 'H'
    while len(string) < n:
        if n % len(string) == 0:
            string += string
            count += 1
        else:
            string += string[0]
            count += 1
    if len(string) == n:
        return count
    else:
        return 0


"H" "HH" "HHH" "HHHHHH" "HHHHHHHHH"
"H" "HH" ""
"H" "HH" "HHH" "HHHHHH" "HHHHHHHHH" "HHHHHHHHHHHH"
