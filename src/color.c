#include "graphic.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return (placement / distance);
}

static int	get_light(int start, int end, double pctg)
{
	return ((int)((1 - pctg) * start + pctg * end));
}

void	color(t_point *point, t_point *point2, t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	pctg;

	//printf("HOLA\n");
	if (line->color == point2->color)
		;
	else
	{
		if (line->dx > line->dy)
			pctg = percent(point->x, point2->x, line->x);
		else
			pctg = percent(point->y, point2->y, line->y);
		red = get_light((point->color >> 16)
				& 0xFF, (point2->color >> 16) & 0xFF, pctg);
		green = get_light((point->color >> 8)
				& 0xFF, (point2->color >> 8) & 0xFF, pctg);
		blue = get_light(point->color & 0xFF, point2->color & 0xFF, pctg);
		line->color = ((red << 16) | (green << 8) | blue);
	}
}
