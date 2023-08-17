#!/usr/bin/python3


def canUnlockAll(boxes):
    new_list = []

    for box in boxes:
        if len(box) == 0:
            boxes.pop(boxes.index(box))
        if len(box) == 1 and box[0] != 0:
            new_list.append(box)
        elif len(box) > 1:
            for key in box:
                if box not in new_list:
                    new_list.append(box)

    if len(boxes) == len(new_list):
        return True
    return False
