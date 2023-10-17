#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """minOperations function"""
    count = 0
    len_str = 1
    i = 0
    while len_str < n:
        if n % len_str == 0:
            i = len_str
            len_str *= 2
            count += 2
        else:
            len_str += i
            count += 1
    return count


"H" "HH" "HHH" "HHHHHH" "HHHHHHHHH"

" i = 4 len = 12 count = 7 "
"H" "HH" "HHHH"

"H" "HH" "HHH" "HHHHHH" "HHHHHHHHH" "HHHHHHHHHHHH"
