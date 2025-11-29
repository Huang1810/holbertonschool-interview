#!/usr/bin/python3
"""
Prime Game Module

Maria and Ben play x rounds of a game using the set of numbers 1 through n.
Players alternate picking a prime number and removing that number and all of
its multiples. The player who cannot make a valid move loses.

This function determines which player wins the most rounds.
"""


def isWinner(x, nums):
    """
    Determine the overall winner of the Prime Game.

    Args:
        x (int): Number of rounds.
        nums (list): List of n values, one for each round.

    Returns:
        str or None: "Maria", "Ben", or None if there is a tie.
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)

    # Sieve of Eratosthenes to mark primes up to max_n
    sieve = [True] * (max_n + 1)
    sieve[0] = False
    sieve[1] = False

    limit = int(max_n ** 0.5)
    for i in range(2, limit + 1):
        if sieve[i]:
            start = i * i
            for j in range(start, max_n + 1, i):
                sieve[j] = False

    # Build prefix array of number of primes up to each index
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(1, max_n + 1):
        if sieve[i]:
            count += 1
        prime_count[i] = count

    # Evaluate each game round
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        # Odd number of primes → Maria wins
        if prime_count[n] % 2:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
