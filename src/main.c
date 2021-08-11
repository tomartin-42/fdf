#include "graphic.h"

int	main(int argc, char **argv)
{
	//t_map	map;
	void	*mlx;
	void	*mlx_win;
	
	check_correct_argc(argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 1200, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 80, 80, 0x00FFFFFF);
	mlx_pixel_put(mlx, mlx_win, 100, 100, 0x00FFFFFF);
	mlx_loop(mlx);
}

/*void	read_map (char **argv, t_map *map)
{
}*/
