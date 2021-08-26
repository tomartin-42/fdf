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
	printf("HOLA\n");
	calculate_true_center(map);
	if(map->scale < 1)
		map->scale = 1;
}

t_point	size_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	//z = (map->xy[x][y]) * sin(M_PI / 6);
	z = (map->xy[x][y]) / 1.6; 
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
	printf("y_u = %d, %d\n", map->y_u[0], map->y_u[1]);
	printf("y_d = %d, %d\n", map->y_d[0], map->y_d[1]);
	adjust_and_scale (map);
}

void	adjust_and_scale (t_map *map)
{
	t_point	point;
	t_point	point2;
	float	div_x;

	point = size_points(map, map->y_d[0], map->y_d[1]);
	point2 = size_points(map, map->y_u[0], map->y_u[1]);
	map->scale = 200;
	while ((point2.y * map->scale) - (point.y * map->scale) > 1040)
		map->scale -= 0.2;
	point = size_points(map, 0, 0);
	point2 = size_points(map, map->x - 1, map->y - 1);
	while ((point2.y * map->scale) - (point.y * map->scale) > 1910)
		map->scale -= 0.2;
	point = size_points(map, map->y_d[0], map->y_d[1]);
	while ((point.y * map->scale) + map->center_y < 10)
		map->center_y += 1;
	point = size_points(map, 0, map->y -1);
	point2 = size_points(map, map->x - 1, 0);
	div_x = (point2.x - point.x);
	printf("%f %f\n", point2.x, point.x);
	map->center_x = (1920 - abs((int) div_x)) ;
	map->center_x = map->center_x /= 2 ;
	printf("%d --- %f\n", map->center_x, div_x);
	printf("Escala= %f\n", map->scale);
}
