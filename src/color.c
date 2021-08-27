#include "graphic.h"

void	color(t_point *point, t_point *point2)
{
	t_color clr;
	t_color clr2;	
	t_color diff_c;
	int	dist_x;
	int dist_y;
	int	dtot;
	
//	printf("color: %X\n", point->color);	
	//point->color = 0x00ffffff;
	clr = dismount_color(point->color);
	clr2 = dismount_color(point2->color);
	//printf("1 - t: %X\nr: %X\ng: %X\nb: %X\n", clr.t, clr.r, clr.g, clr.b);
	//printf("2 - t: %X\nr: %X\ng: %X\nb: %X\n", clr2.t, clr2.r, clr2.g, clr2.b);
	dist_x = point2->x - point->x;
	dist_y = point2->y - point->y;
	dtot = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
	diff_c = diff_color(clr, clr2, dtot);
	clr =	aply_diff(clr, diff_c);
	//printf("T - t: %X\nr: %X\ng: %X\nb: %X\n", clr.t, clr.r, clr.g, clr.b);
	point->color = create_trgb(clr.t, clr.r, clr.g, clr.b);
	//	printf("%x color= %X\n", c_inc, point->color);
}

t_color dismount_color (int color)
{
	t_color	clr;

	clr.t = get_t(color);
	clr.r = get_r(color);
	clr.g = get_g(color);
	clr.b = get_b(color);
	return(clr);
}

t_color	diff_color(t_color color, t_color color2, int dtot)
{
	t_color inc_color;

	inc_color.t = (color2.t - color.t) / dtot;
	inc_color.r = (color2.r - color.r) / dtot;
	inc_color.g = (color2.g - color.g) / dtot;
	inc_color.b = (color2.b - color.b) / dtot;
	return(inc_color);
}

t_color aply_diff(t_color color, t_color diff_color)
{
	t_color aux;

	aux.t = color.t + diff_color.t;
	aux.r = color.r + diff_color.r;
	aux.g = color.g + diff_color.g;
	aux.b = color.b + diff_color.b;
	return(aux);
}
