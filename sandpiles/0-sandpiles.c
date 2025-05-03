#include <stdio.h>
#include "sandpiles.h"

/**
 * is_unstable - Checks if the sandpile is unstable (any cell > 3)
 * @grid: The 3x3 grid
 *
 * Return: 1 if unstable, 0 otherwise
 */
static int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);

	return (0);
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - Performs a single toppling round
 * @grid: The 3x3 grid to topple (in-place)
 */
static void topple(int grid[3][3])
{
	int temp[3][3] = {0};
	int i, j;

	/* Apply toppling logic */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j]++;
				if (i < 2)
					temp[i + 1][j]++;
				if (j > 0)
					temp[i][j - 1]++;
				if (j < 2)
					temp[i][j + 1]++;
			}
		}
	}

	/* Apply changes to grid */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 grid (modified in place)
 * @grid2: Second 3x3 grid (added to grid1)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Keep toppling until stable */
	while (is_unstable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
