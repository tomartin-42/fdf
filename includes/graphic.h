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
}	t_map;

void	check_correct_argc(int argc, char **argv);

void	execut_error (void);

#endif
