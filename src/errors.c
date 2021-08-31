#include "../includes/graphic.h"

void	execut_error(int errornum)
{
	printf("%s\n", strerror(errornum));
	exit(errornum);
}

void	freeall(t_map *map)
{
	int	i;
	int	j;

	i = map->x - 1;
	j = map->y - 1;
	while (i >= 0)
	{
		free(map->xy[i]);
		free(map->color[i]);
		i--;
	}
	free(map->xy);
	free(map->color);
}
