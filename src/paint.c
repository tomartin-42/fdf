#include "graphic.h"

void	paint_point(t_map *map, void *mlx, void *mlx_win)
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
			if (i < map->x)
			{
				if (i + 1 < map->x)
				point2 = calculate_points(map, i + 1, j);
				draw_line(point, point2, mlx, mlx_win);
			}
			if (j < map->y - 1)
			{
				if (j + 1 < map->y)
				point2 = calculate_points(map, i, j + 1);
				draw_line(point, point2, mlx, mlx_win);
			}
		//	mlx_pixel_put(mlx, mlx_win, point.x, point.y, point.color);
			j++;
		}
		i++;
	}
}

void	print_line_low(t_point point, t_point point2, void *mlx, void *mlx_win)
{
	float	yi;
	t_line	line;
	
	line.dx = point2.x - point.x;
	line.dy = point2.y - point.y;
	yi = 1;
	if (line.dy < 0)
	{
		yi = -1;
		line.dy = -line.dy;
	}
	line.D = (2 * line.dy) - line.dx;
	line.y =(int) point.y;
	line.x = (int) point.x;
	while (line.x < point2.x)
	{
		mlx_pixel_put(mlx, mlx_win, line.x, line.y, point2.color);
		if (line.D > 0)
		{
			line.y = line.y + yi ;
			line.D = line.D + (2 * (line.dy - line.dx));
		}
		else
			line.D = line.D + 2 * line.dy;
		line.x++;
	}
}
void	print_line_high(t_point point, t_point point2,  void *mlx, void *mlx_win)
{
	float	xi;
	t_line	line;
	
	line.dx = point2.x - point.x;
	line.dy = point2.y - point.y;
	xi = 1;
	if (line.dx < 0)
	{
		xi = -1;
		line.dx = -line.dx;
	}
	line.D = (2 * line.dx) - line.dy;
	line.y = point.y;
	line.x = point.x;
	while (line.y < point2.y)
	{
	//	printf ("%f - %f\n", line.y, point.y);
		mlx_pixel_put(mlx, mlx_win, line.x, line.y, point2.color);
		if (line.D > 0)
		{
			line.x = line.x + xi;
			line.D = line.D + (2 * (line.dx -line.dy));
		}
		else
			line.D = line.D + 2 * line.dx;
		line.y++;
	}
}

void	draw_line(t_point point, t_point point2, void *mlx, void *mlx_win)
{
	if (fabsf(point2.y - point.y) < fabsf(point2.x - point.x))
	{	
		if (point.x > point2.x)
			print_line_low(point2, point, mlx, mlx_win);
		else
			print_line_low(point, point2, mlx, mlx_win);
	}
	else
	{
		if (point.y > point2.y)
			print_line_high(point2, point, mlx, mlx_win);
		else
		{	
			print_line_high(point, point2, mlx, mlx_win);
		
		}
	}	
}

t_point	calculate_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	point.color = map->color[x][y];
	z = (map->xy[x][y]);
	point.x = (y - x) * cos (M_PI / 6) * map->scale;
	point.y = ((x + y - z) * sin (M_PI / 6)) * map->scale;
	point.x = point.x + map->center_x;
	point.y = point.y + map->center_y;
	return (point);
}
