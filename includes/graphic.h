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
}	t_map;

typedef struct s_point{
	int	x;
	int	y;
	int	nx;
	int	ny;
}	t_point;

typedef struct s_line{
	int	x;
	int 	y;
	int	D;
}	t_line;

# define X_MED 360
# define Y_MED 640	

int	check_correct_argc(int argc, char **argv);
t_map	check_fd_map(int fd);

void	execut_error (void);

void	get_y(t_map *map, char *line);
void	dimension_map(t_map *map, int fd);

void	copy_to_map(t_map *map, char *argv);

void	calculate_scale(t_map *map);

void	paint_point(t_map *map, void *mlx, void *mlx_win);
void	print_line_low(t_point point, void *mlx, void *mlx_win);
void	print_line_high(t_point point, void *mlx, void *mlx_win);
t_point	calculate_points(t_map *map, int x, int y);

void printmap(t_map *map);
#endif
