#include "graphic.h"

//calculate the map scale and center this.
void	calculate_scale(t_map *map)
{
	map->center_x = 0;
	map->center_y = 0;
	map->y_u[0] = 0;
	map->y_u[1] = 0;
	map->y_d[0] = 0;
	map->y_d[1] = 0;
	calculate_true_center(map);
	if (map->scale < 1)
		map->scale = 1;
}

t_point	size_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	z = (map->xy[x][y]) / 3;
	point.x = (y - x) * cos (M_PI / 6);
	point.y = ((x + y - z) * sin (M_PI / 6));
	return (point);
}

static void	get_p(t_map *map, int i, int j, int control)
{
	if (control == 1)
	{
		map->y_u[0] = i;
		map->y_u[1] = j;
	}
	else
	{
		map->y_d[0] = i;
		map->y_d[1] = j;
	}
}

void	calculate_true_center(t_map *map)
{
	int		i;
	int		j;
	t_point	point;
	t_point	point2;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			point = size_points(map, i, j);
			point2 = size_points(map, map->y_u[0], map->y_u[1]);
			if (point.y > point2.y)
				get_p(map, i, j, 1);
			point2 = size_points(map, map->y_d[0], map->y_d[1]);
			if (point.y < point2.y)
				get_p(map, i, j, 2);
			j++;
		}
		i++;
	}
	adjust_and_scale (map);
}

void	adjust_and_scale(t_map *map)
{
	t_point	point;
	t_point	point2;

	point = size_points(map, map->y_d[0], map->y_d[1]);
	point2 = size_points(map, map->y_u[0], map->y_u[1]);
	map->scale = 2000;
	while ((point2.y * map->scale) - (point.y * map->scale) > 1040)
		map->scale -= 0.2;
	point = size_points(map, 0, 0);
	point2 = size_points(map, map->x - 1, map->y - 1);
	while ((point2.y * map->scale) - (point.y * map->scale) > 1910)
		map->scale -= 0.2;
	point = size_points(map, map->y_d[0], map->y_d[1]);
	while ((point.y * map->scale) + map->center_y < 10)
		map->center_y += 1;
	point = size_points(map, map->x / 2, map->y / 2);
	if ((point.x * map->scale) < 960)
		while (((point.x * map->scale) + map->center_x) < 960)
			map->center_x += 1;
	else if ((point.x * map->scale) > 960)
		map->center_x -= 1;
}
