#include "graphic.h"

//calculate the map scale in funtion of size of this.
void calculate_scale(t_map *map)
{
	float	h;
	int	i;
	int	j;

	i = 0;
	h = 0;
	while (i < map-> x)
	{
		j = 0;
		while (j < map-> y)
		{
			if (abs(map->xy[i][j]) <= h)
				h = abs(map->xy[i][j] + j);
			else if (i > h)
				h = i;
			j++;
		}
		i++;
	}
	if ((X_MED) > (h / 2))
		map->scale = ((X_MED - 10)) / (h / 2);
	else
		map->scale =  ((Y_MED - 10)) / (h / 2);
	center_map(map);
	printf("%d - %d",map->center_x, map->center_y);	
}

void	center_map(t_map *map)
{
	printf("KKKKKKK\n");
	map->center_x = map->scale * (X_MED);
	map->center_y = map->scale * (Y_MED);
}
