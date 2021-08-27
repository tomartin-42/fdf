#include "graphic.h"

void	color(t_point *point, t_point *point2)
{
	int	diff_color;
	int	dist_x;
	int	dist_y;
	int	dtot;
	int	c_inc;
	
	diff_color = point2->color - point->color;
	//if(diff_color != 0)
	//{
		dist_x = fabsf(point2->x - point->x);
		dist_y = fabsf(point2->y - point->y);
		dtot = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
		printf("dist= %d\n", dtot);
		c_inc = (diff_color / dtot);
		point->color += c_inc;
		printf("%x color= %X\n", c_inc, point->color);
	//}
}
