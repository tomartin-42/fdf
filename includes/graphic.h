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
}	t_map;

int	check_correct_argc(int argc, char **argv);
t_map	check_fd_map(int fd);

void	execut_error (void);

void	get_x(t_map *map, char *line);
void	dimension_map(t_map *map, int fd);

void	copy_to_map(t_map *map, char *argv);


void printmap(t_map *map);
#endif
