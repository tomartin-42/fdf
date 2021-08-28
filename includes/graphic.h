#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
//# include <mlx.h>

# include "mlx.h"
# include "libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
} 	t_data;

typedef struct s_map{
	int	**xy;
	int	x;
	int	y;
	float	scale;
	int	y_u[2];
	int	y_d[2];
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
	float	ni;
	float	x;
	float	y;
	float	D;
}	t_line;

typedef struct s_color{
	int			t;
	int		r;
	int		g;
	int		b;
	unsigned int color;
} t_color;

# define Z_MOD 3

int	check_correct_argc(int argc, char **argv);
t_map	check_fd_map(int fd);

void	execut_error (void);

void	get_y(t_map *map, char *line);
void	dimension_map(t_map *map, int fd);
void	init_color(t_map *map);

void	copy_to_map(t_map *map, char *argv);
void	get_color(t_map *map, char *str, int i, int j);

void	calculate_scale(t_map *map);
t_point	size_points(t_map *map, int x, int y);
void	calculate_true_center(t_map *map);
void	adjust_and_scale(t_map *map);

void	paint_point(t_map *map, t_data *data);
void	print_line_low(t_data *data, t_point point, t_point point2);
void	print_line_high(t_data *data, t_point  point, t_point point2);
t_point	calculate_points(t_map *map, int x, int y);
void	draw_line(t_data *data, t_point point, t_point point2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	color(t_point *point, t_point *point2);
t_color	dismount_color(int color);
t_color	diff_color(t_color color, t_color color2, int dtot);
t_color aply_diff(t_color color, t_color diff_color);

void printmap(t_map *map);

int get_t(int color);
int get_r(int color);
int get_g(int color);
int get_b(int color);
int create_trgb(int t, int r, int g, int b);

#endif
