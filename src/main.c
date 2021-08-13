#include "graphic.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	
	int	ini = 300;
	int	i;
	int	j;
	fd = check_correct_argc(argc, argv);
	map = check_fd_map(fd);
	copy_to_map(&map, argv[1]);
//	printmap(&map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	i = 0;
	while (i < map.x)
	{
		j = 0;
		while(j < map.y)
		{
			//i = i + 300;
			//j = j + 300;
			//j = i - j;
			//i = (j + i) / 2;
			mlx_pixel_put(mlx, mlx_win, ini +  (((i - j) * cos (M_PI / 6)) * 50) , ini +  (((j + i) * sin (M_PI / 6)) * 50), 0x00FFFFFF);
			j++;
		}
		i++;
	}
//	mlx_pixel_put(mlx, mlx_win, 100, 100, 0x00FFFFFF);
	mlx_loop(mlx);
}

/*void	read_map (char **argv, t_map *map)
{
}*/
