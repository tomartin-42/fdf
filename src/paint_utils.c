#include "graphic.h"

//Print point and check if poin is out of map
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < 1919) && (y > 0 && y < 1079))
	{
		dst = data->addr + ((y) * data->line_length
				+ (x) * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	get_gradient(t_line *line, t_point point, t_point point2)
{
	line->dx = point2.x - point.x;
	line->dy = point2.y - point.y;
	line->color = point.color;
	line->ni = 1;
}

t_point	calculate_points(t_map *map, int x, int y)
{
	t_point	point;
	float	z;

	point.color = map->color[x][y];
	z = (map->xy[x][y]) / 3;
	point.x = (y - x) * cos (M_PI / 6) * map->scale;
	point.y = ((x + y - z) * sin (M_PI / 6)) * map->scale;
	point.x = point.x + map->center_x;
	point.y = point.y + map->center_y;
	return (point);
}
