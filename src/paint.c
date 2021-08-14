#include "graphic.h"

void	paint_point(t_map *map, void *mlx, void *mlx_win)
{
	int	i;
	int	j;
	int	ini = 200;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while(j < map->x)
		{
			mlx_pixel_put(mlx, mlx_win, ini +  (((j - i) * cos (M_PI / 6)) * 10) , ini +  (((j + i - map->xy[i][j] ) * sin (M_PI / 6)) * 10), 0x00FFFFFF);
			j++;
		}
		i++;
	}
}


