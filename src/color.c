#include "graphic.h"

void	color(t_point *point, t_point *point2)
{
	t_color clr;
	t_color clr2;	
	t_color diff_c;
	int	dist_x;
	int 	dist_y;
	int	dtot;
	
	printf("color_i: %d\n", point->color);	
	printf("color_f: %d\n", point2->color);	
	//point->color = 0x00ffffff;
//	if (point->color > point2->color)
//	{
//		clr = dismount_color(point2->color);
//		clr2 = dismount_color(point->color);
//	}
//	else
//	{
		clr = dismount_color(point->color);
		clr2 = dismount_color(point2->color);
//	}
	printf("1 - t: %d\nr: %d\ng: %d\nb: %d\n", clr.t, clr.r, clr.g, clr.b);
	printf("2 - t: %d\nr: %d\ng: %d\nb: %d\n", clr2.t, clr2.r, clr2.g, clr2.b);
	dist_x = point2->x - point->x;
	dist_y = point2->y - point->y;
	dtot = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
	diff_c = diff_color(clr, clr2, dtot);
	printf("D - t: %d\nr: %d\ng: %d\nb: %d\n", diff_c.t, diff_c.r, diff_c.g, diff_c.b);
	clr =aply_diff(clr, diff_c);
	point->color = create_trgb(clr.t, clr.r, clr.g, clr.b);
	printf("Color_i out= %d\n", point->color);
	printf("Color_f out= %d\n", point2->color);
	printf("dtot: %d\n", dtot);
	printf("------------------------------\n");
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

		inc_color.t = (int)(color2.t - color.t);
		inc_color.r = (int)(color2.r - color.r) / 10;
		inc_color.g = (int)(color2.g - color.g) / 100;
		inc_color.b = (int)(color2.b - color.b) / 10;
		dtot = 0;
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
