#!/usr/bin/python3
"""0-nqueens.py"""

import sys


def is_safe(board, row, col):
    """Check this column on upper side"""
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n, row=0, board=[]):
    """places queens recursively"""
    if row == n:
        print([[i, board[i]] for i in range(n)])  # Print board positions
        return

    for col in range(n):
        if is_safe(board, row, col):
            board.append(col)  # Place queen
            solve_nqueens(n, row + 1, board)
            board.pop()


def main():
    """main function"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
        if n < 4:
            print("N must be at least 4")
            sys.exit(1)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    board = []
    solve_nqueens(n, 0, board)


if __name__ == "__main__":
    main()
