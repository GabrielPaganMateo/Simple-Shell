#include "header.h"
/**
 * free_grid - frees an array of pointers to pointers
 * @grid: array of pointers
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
