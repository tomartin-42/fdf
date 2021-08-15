#include "graphic.h"

void	paint_point(t_map *map, void *mlx, void *mlx_win)
{
	int	i;
	int	j;
	t_point	point;
	t_point	point2;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while(j < map->x)
		{
			point = calculate_points(map, i, j);
			if (i < map->y - 1)
			{
			//	point2 = calculate_points(map, i + 1, j);
			//	print_line_low(point, point2, mlx, mlx_win);
			}
			if (j < map->x - 1)
			{
				point2 = calculate_points(map, i, (j + 1));
				print_line_low(point2, point, mlx, mlx_win);
			}
			//point2 = calculate_points(map, i, j + 1 );
			//print_line_high(point2, point, mlx, mlx_win);
			mlx_pixel_put(mlx, mlx_win, point.x, point.y, 0x0000FF00);
			j++;
		}
		i++;
	}
}

void	print_line_low(t_point point, t_point point2, void *mlx, void *mlx_win)
{
	float	dx;
	float	dy;
	float	yi;
	t_line	line;
	
	dx = point2.x - point.x;
	dy = point2.y - point.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	line.D = (2 * dy) - dx;
	line.y = point.y;
	line.x = point.x;
	while (line.x <= point2.x)
	{
		mlx_pixel_put(mlx, mlx_win, line.x, line.y, 0x00FFFFFF);
		if (line.D > 0)
		{
			line.y = line.y + yi ;
			line.D = line.D + (2 * (dy - dx));
		}
		else
			line.D = line.D + 2 * dy;
		line.x++;
	}
}
void	print_line_high(t_point point, t_point point2,  void *mlx, void *mlx_win)
{
	float	dx;
	float	dy;
	float	xi;
	t_line	line;
	
	dx = point2.x - point.x;
	dy = point2.y - point.y;
	xi = 1;
	if (dy < 0)
	{
		xi = -1;
		dx = -dx;
	}
	line.D = (2 * dx) - dy;
	line.y = point.y;
	line.x = point.x;
	while (line.y <= point2.y)
	{
		mlx_pixel_put(mlx, mlx_win, line.x, line.y, 0x00FFFFFF);
		if (line.D > 0)
		{
			line.x = line.x + xi;
			line.D = line.D + (2 * (dx -dy));
		}
		else
			line.D = line.D + 2 * dx;
		line.y++;
	}
}

/*void	draw_line(t_map *map, t_point point, void *mlx, void *mlx_win)
{
}*/

t_point	calculate_points(t_map *map, int x, int y)
{
	t_point	point;
	float	a;

	a = (map->xy[x][y] * sin(M_PI / 6));
	point.x = (x - y) * cos (M_PI / 6) * map->scale;
	point.y = ((x + y - a) * sin (M_PI / 6)) * map->scale;
	point.x = point.x + 650;
	point.y = point.y + 100;
	return (point);
} 
