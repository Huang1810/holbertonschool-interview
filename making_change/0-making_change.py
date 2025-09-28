#!/usr/bin/python3
"""
Function to determine the fewest number of coins needed to meet a given amount.
"""

def makeChange(coins, total):
    if total <= 0:
        return 0

    # Use a large number to represent infinity
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 coins to make 0 total

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
