#include "graphic.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	fd = check_correct_argc(argc, argv);
	map = check_fd_map(fd);
	printf("%d . %d\n", map.x, map.y);
	copy_to_map(&map, argv[1]);
//	init_color(&map);
//	printmap(&map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, argv[1]);
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	calculate_scale(&map);
	paint_point(&map, mlx, mlx_win); 
	mlx_loop(mlx);
}

