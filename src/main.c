#include "graphic.h"

static int	key_hook(int keycode, void *mlx, void *mlx_win)
{
	if (keycode == 53)
	{
		mlx_clear_window(mlx, mlx_win);
		mlx_destroy_window(mlx, mlx_win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	fd = check_correct_argc(argc, argv);
	map = check_fd_map(fd);
	copy_to_map(&map, argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, argv[1]);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	calculate_scale(&map);
	paint_point(&map, &img); 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &mlx);
	mlx_loop(mlx);
}
