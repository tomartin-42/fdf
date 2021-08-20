#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "mlx.h"
# include "libft.h"

typedef struct s_map{
	int	**xy;
	int	x;
	int	y;
	int	scale;
	int	center_x;
	int	center_y;
	int	**color;
}	t_map;

typedef struct s_point{
	float	x;
	float	y;
	int	color;
}	t_point;

typedef struct s_line{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	D;
}	t_line;

# define Y_MED 360
# define X_MED 640	

int	check_correct_argc(int argc, char **argv);
t_map	check_fd_map(int fd);

void	execut_error (void);

void	get_y(t_map *map, char *line);
void	dimension_map(t_map *map, int fd);
void	init_color(t_map *map);

void	copy_to_map(t_map *map, char *argv);

void	calculate_scale(t_map *map);
t_point	size_points(t_map *map, int x, int y);
void	calculate_true_scale(t_map *map);
void	calculate_true_center(t_map *map);
void	calculate_scale_final(t_map *map);

void	paint_point(t_map *map, void *mlx, void *mlx_win);
void	print_line_low(t_point point, t_point point2, void *mlx, void *mlx_win);
void	print_line_high(t_point point, t_point point2, void *mlx, void *mlx_win);
t_point	calculate_points(t_map *map, int x, int y);
void	draw_line(t_point point, t_point point2, void *mlx, void *mlx_win);

void printmap(t_map *map);
#endif
