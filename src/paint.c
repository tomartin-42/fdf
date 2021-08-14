#include "graphic.h"

void	paint_point(t_map *map, void *mlx, void *mlx_win)
{
	int	i;
	int	j;
	t_point	point;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while(j < map->x)
		{
			point = calculate_points(map, i, j);
			mlx_pixel_put(mlx, mlx_win, point.x, point.y, 0x00FFFFFF);
			print_line_high(point, mlx, mlx_win);
			j++;
		}
		i++;
	}
}

void	print_line_low(t_point point, void *mlx, void *mlx_win)
{
	int	dx;
	int	dy;
	int	yi;
	t_line	line;
	
	dx = point.nx - point.x;
	dy = point.ny - point.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	line.D = (2 * dy) - dx;
	line.y = point.y;
	line.x = point.x;
	while (line.x <= point.nx)
	{
		mlx_pixel_put(mlx, mlx_win, line.x, line.y, 0x00FFFFFF);
		if (line.D > 0)
		{
			line.y = line.y + yi;
			line.D = line.D + (2 * (dy -dx));
		}
		else
			line.D = line.D + 2 * dy;
		line.x++;
	}
}
void	print_line_high(t_point point, void *mlx, void *mlx_win)
{
	int	dx;
	int	dy;
	int	xi;
	t_line	line;
	
	dx = point.nx - point.x;
	dy = point.ny - point.y;
	xi = 1;
	if (dy < 0)
	{
		xi = -1;
		dx = -dx;
	}
	line.D = (2 * dx) - dy;
	line.y = point.y;
	line.x = point.x;
	while (line.y <= point.ny)
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
	int	a;
	int	na;

	a = (map->xy[x][y] * sin(M_PI / 6));
	point.x = (x - y) * cos (M_PI / 6) * map->scale;
	point.y = ((x + y - a) * sin (M_PI / 6)) * map->scale;
	point.x = point.x + 650;
	point.y = point.y + 100;
	na = (map->xy[x + 1][y + 1] * sin(M_PI / 6));
	point.nx = (x + 1 - y + 1) * cos (M_PI / 6) * map->scale;
	point.ny = ((x + 1 + y + 1 - na) * sin (M_PI / 6)) * map->scale;
	point.nx = point.x + 650;
	point.ny = point.y + 100;
	return (point);
}
	
