#!/usr/bin/python3
"""
Calculates how much water will be retained after it rains.
"""


def rain(walls):
    """
    Args:
        walls: list of non-negative integers representing wall heights

    Returns:
        Integer indicating total water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    water = 0

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water trapped
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]

    return water
