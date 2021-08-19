#include "graphic.h"

//calculate the map scale in funtion of size of this.
void calculate_scale(t_map *map)
{
//	float	h;
/*	int	i;
	int	j;
	t_point	point;

	i = 0;
	h = 1;
	while (i < map-> x)
	{
		j = 0;
		while (j < map-> y)
		{
			point = size_points(map, i, j);
			printf ("[[%f - %f\n]]", point.x, point.y);
			j++;
		}
		i++;
	}
	if ( h > (map->y))
	{
		printf("H1\n");
		map->scale = ((map->x)) * (h);
	}
	else
	{
		printf("H2\n");
		map->scale =  (map->y) / (h);
	}*/
	map->center_x = X_MED;
	map->center_y = Y_MED;
	map->scale = 1000;
	calculate_true_scale(map);
	calculate_true_center(map);
	map->scale = 1000;
	calculate_scale_final(map);
//	printf("scale = %d %f\n", map->scale, h);
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

void	calculate_true_scale(t_map *map)
{
	int	i;
	int	j;
	t_point	point;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			point = size_points(map, i, j);
			while ((point.x * map->scale) + 640 <= 0 
				|| (point.x * map->scale) + 640 >= 1280)
				map->scale -= 1;	
			while ((point.y * map->scale) + 360 <= 0 
				|| (point.y * map->scale) + 360 >= 720)
				map->scale -= 1;	
			j++;
		}
		i++;
	}
}

void	calculate_true_center(t_map *map)
{
	t_point	point;

	map->center_x = 0;
	map->center_y = 0;
	point = size_points(map,(int) map->x / 2, (int) map->y / 2);
	while ((point.x * map->scale) + map->center_x < X_MED) 
		map->center_x += 1;	
	while ((point.y * map->scale) + map->center_y < Y_MED)
		map->center_y += 1;	
	printf("%d ------ %d\n", map->center_x,map->center_y);
}
			
void	calculate_scale_final(t_map *map)
{
	int	i;
	int	j;
	t_point	point;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			point = size_points(map, i, j);
			while ((point.x * map->scale) + map->center_x <= 0 
				|| (point.x * map->scale) + map->center_x >= 1280)
				map->scale -= 1;	
			while ((point.y * map->scale) + map->center_y <= 0 
				|| (point.y * map->scale) + map->center_y >= 720)
				map->scale -= 1;
			j++;
		}
		i++;
	}
}
