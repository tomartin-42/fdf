#include "graphic.h"

void	paint_point(t_map *map, t_data *img)
{
	int	i;
	int	j;
	t_point	point;
	t_point	point2;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while(j < map->y)
		{
			point = calculate_points(map, i, j);
			if (i < map->x && i + 1 < map->x)
			{
				point2 = calculate_points(map, i + 1, j);
				draw_line(img, point, point2);
			}
			if (j < map->y && j + 1 < map->y)
			{	
				point2 = calculate_points(map, i, j + 1);
				draw_line(img, point, point2);
			}
			j++;
		}
		i++;
	}
}

void	print_line_low(t_data *data, t_point point, t_point point2)
{
	t_line	line;
	
	line.dx = point2.x - point.x;
	line.dy = point2.y - point.y;
	line.ni = 1;
	if (line.dy < 0)
	{
		line.ni = -1;
		line.dy = -line.dy;
	}
	line.D = (2 * line.dy) - line.dx;
	line.y =(int) point.y;
	line.x = (int) point.x;
	while (line.x < point2.x)
	{
		my_mlx_pixel_put(data, (int)line.x, (int)line.y, point2.color);
		if (line.D > 0)
		{
			line.y = line.y + line.ni;
			line.D = line.D + (2 * (line.dy - line.dx));
		}
		else
			line.D = line.D + 2 * line.dy;
		line.x++;
	}
}

void	print_line_high(t_data *data, t_point point, t_point point2)
{
	t_line	line;
	
	line.dx = point2.x - point.x;
	line.dy = point2.y - point.y;
	line.ni = 1;
	if (line.dx < 0)
	{
		line.ni = -1;
		line.dx = -line.dx;
	}
	line.D = (2 * line.dx) - line.dy;
	line.y = point.y;
	line.x = point.x;
	while (line.y < point2.y)
	{
		my_mlx_pixel_put(data, (int)line.x, (int)line.y, point2.color);
		if (line.D > 0)
		{
			line.x = line.x + line.ni;
			line.D = line.D + (2 * (line.dx -line.dy));
		}
		else
			line.D = line.D + 2 * line.dx;
		line.y++;
	}
}

void	draw_line(t_data *data, t_point point, t_point point2)
{
	if (fabsf(point2.y - point.y) < fabsf(point2.x - point.x))
	{	
		if (point.x > point2.x)
			print_line_low(data, point2, point);
		else
			print_line_low(data, point, point2);
	}
	else
	{
		if (point.y > point2.y)
			print_line_high(data, point2, point);
		else
			print_line_high(data, point, point2);
	}	
}

t_point	calculate_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	//point.color = map->color[x][y];
	point.color = 0x00FFFFFF;
	//printf ("----%d %d----\n",x ,y);
	//z = (map->xy[x][y]) * sin(M_PI / 6);
	z = (map->xy[x][y]);
	point.x = (y - x) * cos (M_PI / 6) * map->scale;
	point.y = ((x + y - z) * sin (M_PI / 6)) * map->scale;
	point.x = point.x + map->center_x;
	point.y = point.y + map->center_y;
//	printf("++ %f %f ++\n", point.x, point.y);
//	printf("++ %d %d ++\n", map->center_x, map->center_y);
	return (point);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
