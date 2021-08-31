#include "graphic.h"

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
