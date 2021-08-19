#include "graphic.h"

//calculate the map scale in funtion of size of this.
void calculate_scale(t_map *map)
{
	int	h;
	int	i;
	int	j;
	t_point	point;

	i = 0;
	h = 0;
	while (i < map-> x)
	{
		j = 0;
		while (j < map-> y)
		{
			point = size_points(map, i, j);
			if (fabs(point.y) >= h)
				h = (int) point.y;
			else if (fabs(point.x) >= h)
				h = (int) point.x;
			j++;
		}
		i++;
	}
	if ( h > (map->y))
	{
		printf("H1\n");
		map->scale = ((Y_MED - 40)) / (h);
	}
	else
	{
		printf("H2\n");
		map->scale =  (X_MED - 80) / (h);
	}
	printf("scale = %d %d\n", map->scale, h);
	center_map(map);
}

void	center_map(t_map *map)
{
	int	center[2];

	center[0] = map->x / 2 - 640;
	center[1] = map->y / 2 - 360;
	map->center_x = (1240 / map->x) * center[0];
	map->center_y = (700 / map->y) * center[1];

}

t_point	size_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	z = (map->xy[x][y]);
	point.x = (y - x) * cos (M_PI / 6);
	point.y = ((x + y - z) * sin (M_PI / 6));
	return (point);
}
