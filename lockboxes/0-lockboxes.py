#!/usr/bin/python3
"""This method determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    new_list = []

    for box in boxes:
        if len(box) == 0:
            boxes.pop(boxes.index(box))
        elif len(box) == 1:
            new_list.append(box)
        elif len(box) > 1:
            temp_box = []
            for key in box:
                if key <= len(boxes) and key not in new_list:
                    temp_box.append(key)
            box[:] = temp_box  # Replace the original box with temp_box

    if len(boxes) == len(new_list):
        return True
    return False
