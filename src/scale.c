#include "graphic.h"

//calculate the map scale in funtion of size of this.
void calculate_scale(t_map *map)
{
	map->center_x = 0;
	map->center_y = 0;
	map->x_u[0] = 0;
	map->x_u[1] = 0;
	map->y_u[0] = 0;
	map->y_u[1] = 0;
	map->x_d[0] = 0;
	map->x_d[1] = 0;
	map->y_d[0] = 0;
	map->y_d[1] = 0;
	calculate_true_center(map);
	if(map->scale < 1)
		map->scale = 1;
}

t_point	size_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	//z = (map->xy[x][y]) * sin(M_PI / 6);
	z = (map->xy[x][y]); 
	point.x = (y - x) * cos (M_PI / 6);
	point.y = ((x + y - z) * sin (M_PI / 6));
	return (point);
}

void	calculate_true_center(t_map *map)
{
	int	i;
	int	j;
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
			{
				map->y_u[0] = i;
				map->y_u[1] = j;
			}
			point2 = size_points(map, map->y_d[0], map->y_d[1]);
			if (point.y < point2.y)
			{
				map->y_d[0] = i;
				map->y_d[1] = j;
			}
			j++;
		}
		i++;
	}
	adjust_and_scale (map);
}

void	adjust_and_scale (t_map *map)
{
	t_point	point;

	point = size_points(map, map->y_d[0], map->y_d[1]);
	while (point.y + map->center_y < 10)
		map->center_y += 1;
	map->scale = 200;
	point = size_points(map, map->y_u[0], map->y_u[1]);
	while ((point.y * map->scale) + map->center_y > 540)
		map->scale -= 0.2;
	point = size_points(map, map->y_d[0], map->y_d[1]);
	while ((point.y * map->scale) + map->center_y < 0)
		map->center_y += 1;
	map->center_x = 700; 
	map->center_y = 340; 
}
