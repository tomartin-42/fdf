#include "graphic.h"

static int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_clear_window(win->mlx, win->mlx_win);
		mlx_destroy_window(win->mlx, win->mlx_win);
		system("leaks -list fdf");
		exit(0);
	}
	return(0);
}

static int clouse(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
	return(0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_win	win;
	t_data	img;

	fd = check_correct_argc(argc, argv);
	map = check_fd_map(fd);
	copy_to_map(&map, argv[1]);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 1920, 1080, argv[1]);
	img.img = mlx_new_image(win.mlx, 1920, 1080);
	mlx_key_hook(win.mlx_win, key_hook, &win);
	mlx_hook(win.mlx_win, 17, 0, clouse, &win);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	calculate_scale(&map);
	paint_point(&map, &img); 
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	mlx_loop(win.mlx);
}
