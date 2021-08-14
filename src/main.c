#include "graphic.h"

			//mlx_pixel_put(mlx, mlx_win, ini +  (((i - j) * cos (M_PI / 6)) * 10) , ini +  (((j + i - map.xy[i][j] ) * sin (M_PI / 6)) * 10), 0x00FFFFFF);
int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	
	//int	ini = 300;
	fd = check_correct_argc(argc, argv);
	map = check_fd_map(fd);
	copy_to_map(&map, argv[1]);
	printmap(&map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, argv[1]);
	paint_point(&map, mlx, mlx_win); 
	mlx_loop(mlx);
}

/*void	read_map (char **argv, t_map *map)  
{
}*/
