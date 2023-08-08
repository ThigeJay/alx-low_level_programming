#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - generates a 2D grid of integers
 * @width: the number of columns in the grid
 * @height: the number of rows in the grid
 * creates a 2D grid of integers Each cell in the grid is initialized to 0.
 * If memory allocation fails at any point, it cleans up any previously
 * allocated memory before returning NULL.
 *
 * Return: pointer to the first element of the 2D array, or NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int row, col;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (row = 0; row < height; row++)
	{
		grid[row] = malloc(sizeof(int) * width);

		if (grid[row] == NULL)
		{
			for (; row >= 0; row--)
				free(grid[row]);

			free(grid);
			return (NULL);
		}
	}

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
			grid[row][col] = 0;
	}

	return (grid);
}
