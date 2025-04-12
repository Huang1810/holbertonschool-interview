#!/usr/bin/python3

"""
Module 0-lockboxes
This module provides a function to determine if all lockboxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.

    Args:
        boxes (list of lists): List of lists where each list represents a box 
        and contains keys to other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    opened_boxes = set()
    queue = [0]

    while queue:
        current_box = queue.pop(0)
        if current_box not in opened_boxes:
            opened_boxes.add(current_box)

            for key in boxes[current_box]:
                if key not in opened_boxes and 0 <= key < n:
                    queue.append(key)

        if len(opened_boxes) == n:
            return True

    return len(opened_boxes) == n
