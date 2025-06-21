#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * should_draw - Determines if a position in the Menger Sponge should be a '#'
 * @row: Row index of the position
 * @col: Column index of the position
 * Return: 1 if '#' should be drawn, 0 if ' ' should be drawn
 */
static int should_draw(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return 0;
        row /= 3;
        col /= 3;
    }
    return 1;
}

/**
 * menger - Draws a 2D Menger Sponge of specified level
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = (int)pow(3, level);
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            putchar(should_draw(i, j) ? '#' : ' ');
        }
        putchar('\n');
    }
}
