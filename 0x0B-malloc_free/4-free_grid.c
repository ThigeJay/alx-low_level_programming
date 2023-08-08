#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - deallocates a 2D grid of integers
 * @grid: 2D grid of integers
 * @height: height dimension of the grid
 *
 * Description: frees the memory allocated for a 2D grid of integers.
 * It first iterates over each row of the grid, freeing each row,
 * and then finally frees the memory allocated for the grid itself.
 *
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int row_index;

	for (row_index = 0; row_index < height; row_index++)
	{
		free(grid[row_index]);
	}

	free(grid);
}
