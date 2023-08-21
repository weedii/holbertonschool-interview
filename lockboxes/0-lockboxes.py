#!/usr/bin/python3
"""This method determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    new_list = []
    index_list = []

    for box in boxes:
        if len(box) == 0:
            boxes.pop(boxes.index(box))

        if len(box) == 1 and box not in new_list and box[0] <= len(boxes):
            new_list.append(box[0])

        elif len(box) > 1:
            for key in box:
                if key > len(box):
                    continue
                elif key <= len(boxes) and key not in new_list:
                    new_list.append(key)

    for box in boxes:
        if boxes.index(box)+1 not in index_list:
            index_list.append(boxes.index(box)+1)

    new_list.sort()
    index_list.sort()

    if new_list == index_list:
        return True
    return False
