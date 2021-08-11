#include "../includes/graphic.h"

void	check_correct_argc(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		execut_error();
	if (ft_strlen(argv[1]) == 0)
		execut_error(); 
	fd = open (argv[1], O_RDONLY );
	if (fd < 1)
		execut_error();
}

