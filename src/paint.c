/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:00:26 by tommy             #+#    #+#             */
/*   Updated: 2021/09/01 10:23:26 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	paint_point(t_map *map, t_data *img)
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
			point = calculate_points(map, i, j);
			if (i < map->x && i + 1 < map->x)
			{
				point2 = calculate_points(map, i + 1, j);
				draw_line(img, point, point2);
			}
			j++;
		}
		i++;
	}
	paint_point_p(map, img);
}

void	paint_point_p(t_map *map, t_data *img)
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
			point = calculate_points(map, i, j);
			if (j < map->y && j + 1 < map->y)
			{	
				point2 = calculate_points(map, i, j + 1);
				draw_line(img, point, point2);
			}
			j++;
		}
		i++;
	}
	freeall(map);
}

void	print_line_low(t_data *data, t_point point, t_point point2)
{
	t_line	line;

	get_gradient(&line, point, point2);
	if (line.dy < 0)
	{
		line.ni = -1;
		line.dy = -line.dy;
	}
	line.d = (2 * line.dy) - line.dx;
	line.y = point.y;
	line.x = point.x;
	while (line.x < point2.x)
	{
		color(&point, &point2, &line);
		my_mlx_pixel_put(data, (int)line.x, (int)line.y, line.color);
		if (line.d > 0)
		{
			line.y = line.y + line.ni;
			line.d = line.d + (2 * (line.dy - line.dx));
		}
		else
			line.d = line.d + 2 * line.dy;
		line.x++;
	}
}

void	print_line_high(t_data *data, t_point point, t_point point2)
{
	t_line	line;

	get_gradient(&line, point, point2);
	if (line.dx < 0)
	{
		line.ni = -1;
		line.dx = -line.dx;
	}
	line.d = (2 * line.dx) - line.dy;
	line.y = point.y;
	line.x = point.x;
	while (line.y < point2.y)
	{
		color(&point, &point2, &line);
		my_mlx_pixel_put(data, (int)line.x, (int)line.y, line.color);
		if (line.d > 0)
		{
			line.x = line.x + line.ni;
			line.d = line.d + (2 * (line.dx - line.dy));
		}
		else
			line.d = line.d + 2 * line.dx;
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
