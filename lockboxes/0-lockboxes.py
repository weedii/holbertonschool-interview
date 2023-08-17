#!/usr/bin/python3
"""This method determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    new_list = []

    for box in boxes:

        if len(box) == 0:
            boxes.pop(boxes.index(box))
        if len(box) == 1 and box not in new_list and box[0] <= len(boxes):
            new_list.append(box)
        elif len(box) > 1:
            for key in box:
                if key > len(boxes):
                    return False
                elif key <= len(boxes) and box not in new_list:
                    new_list.append(box)

    print(f"boxes---------{boxes}")
    print(f"new_list------{new_list}")
    if len(boxes) == len(new_list):
        return True
    return False
