#!/usr/bin/python3
"""
Prime Game Module

Maria and Ben play x rounds of a game where each round uses the numbers
from 1 to n. Players alternately pick a prime number and remove that
prime and all of its multiples. If a player cannot pick a prime, they lose.

This function determines the overall winner after x rounds.
"""


def isWinner(x, nums):
    """
    Determines the winner of the Prime Game across x rounds.

    Args:
        x (int): Number of rounds.
        nums (list): List of 'n' values for each round.

    Returns:
        str or None: "Maria", "Ben", or None if tied.
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)

    # --- Sieve of Eratosthenes ---
    # sieve[i] = True indicates that i is prime.
    sieve = [True] * (max_n + 1)
    sieve[0] = sieve[1] = False

    limit = int(max_n ** 0.5)
    for i in range(2, limit + 1):
        if sieve[i]:
            step = i * i
            for j in range(step, max_n + 1, i):
                sieve[j] = False

    # --- Prefix array storing number of primes up to each i ---
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(1, max_n + 1):
        if sieve[i]:
            count += 1
        prime_count[i] = count

    # --- Count overall wins ---
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        # If number of primes ≤ n is odd → Maria wins
        if prime_count[n] % 2:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
