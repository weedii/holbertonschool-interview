#!/usr/bin/python3

"""
Script that reads stdin line by line and computes metrics
"""

import sys

FileSize = 0
STATUS = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}
count = 0


def print_stats():
    """Prints file size and status codes"""
    print("File size: {}".format(FileSize))
    for key, value in sorted(STATUS.items()):
        if value > 0:
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) >= 2:
                try:
                    FileSize += int(parts[-1])
                except ValueError:
                    pass

                if parts[-2] in STATUS:
                    STATUS[parts[-2]] += 1

            count += 1
            if count % 10 == 0:
                print_stats()
    finally:
        print_stats()
