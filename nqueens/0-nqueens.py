#!/usr/bin/python3
import sys


def is_safe(queen_positions, row, col):
    """Check if it's safe to place a queen at the current position."""
    for r in range(row):
        c = queen_positions[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(N, row=0, queen_positions=[], solutions=[]):
    """Backtracking function to find all solutions."""
    if row == N:
        solution = [[i, queen_positions[i]] for i in range(N)]
        solutions.append(solution)
        return
    for col in range(N):
        if is_safe(queen_positions, row, col):
            queen_positions.append(col)
            solve_nqueens(N, row + 1, queen_positions, solutions)
            queen_positions.pop()


def main():
    """Main function to handle input and print solutions."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens(N, 0, [], solutions)
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
