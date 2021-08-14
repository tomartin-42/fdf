#include "graphic.h"

void	paint_point(t_map *map, void *mlx, void *mlx_win)
{
	int	i;
	int	j;
	int	ini = 200;
	int	a;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while(j < map->x)
		{
			a = (map->xy[i][j] * sin(M_PI / 6)); 
			mlx_pixel_put(mlx, mlx_win, ini +  (((j - i) * cos (M_PI / 6)) * map->scale) , ini +  (((j + i - a) * sin (M_PI / 6)) * map->scale), 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
