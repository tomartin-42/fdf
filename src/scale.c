#include "graphic.h"

//calculate the map scale in funtion of size of this.
void calculate_scale(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->x_min = 0;
	map->y_min = 0;
//	map->scale = 1000;
	map->center_x = 0;
	map->center_y = 0;
	calculate_true_center(map);
//	calculate_true_scale(map);
	if(map->scale < 1)
		map->scale = 2;
//	map->scale = 1000;
//	calculate_scale_final(map);
	if(map->scale < 1)
		map->scale = 1;
//	printf("scale = %d %f\n", map->scale, h);
}

t_point	size_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	z = (map->xy[x][y]) * sin(M_PI / 6);
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
	int	i;
	int	j;
	int	x_long;
	int	y_long;
	t_point	point;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			point = size_points(map, i, j);
			if((point.x * i) >= map->x_max)
				map->x_max = point.x;	
			if((point.x * i) <= map->x_min)
				map->x_min = point.x;	
			if((point.y * j)>= map->y_max)
				map->y_max = point.y;	
			if((point.y * j)<= map->y_min)
				map->y_min = point.y;	
			j++;
		}
		i++;
	}
	//x_long = abs(map->x_max) + abs(map->x_min);
	//y_long = abs(map->y_max) + abs(map->y_min);
	x_long = map->x_max + map->x_min;
	y_long = map->y_max + map->y_min;
	map->scale = 200;
	while ((map->x_max * map->scale) > 1280 || (map->y_max * map->scale) > 720)
		map->scale -= 1;
	if (map->scale < 1)
		map->scale = 3;
	printf("**long= %d %d **\n", x_long, y_long);
	printf("**max_min %d %d - %d %d**\n", map->x_max, map->y_max, map->x_min, map->y_min);
	map->center_x = 1280 - ((x_long * map->scale) * cos(M_PI / 6));
	map->center_x = (map->center_x / 2);
	map->center_y = 720 - ((y_long * map->scale) * sin(M_PI / 6));
	map->center_y = (map->center_y / 2);
	printf("{{%d}}\n",map->scale);
	printf("center= %d %d\n", map->center_x, map->center_y);
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
