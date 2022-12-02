#include "header.h"
/*
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i] != NULL)
	{
		free(grid[i]);
	}
	free(grid);
}
