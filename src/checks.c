#include "../includes/graphic.h"

//check the correct arguments and return fd
int	check_correct_argc(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		execut_error();
	if (ft_strlen(argv[1]) == 0)
		execut_error(); 
	fd = open (argv[1], O_RDONLY );
	if (fd < 1)
		execut_error();
	return (fd);
}

t_map	check_fd_map(int fd)
{
	char	*line;
	size_t	i;
	t_map	map;

	map.y = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (i < ft_strlen(line))
		{
			if (!ft_strchr("0123456789 +-", line[i]))
				execut_error();
			if (ft_strchr("+-", line[i])
			 && (!ft_strchr("0123456789",line[i + 1])))
				execut_error();
			i++;
			get_x(&map, line);
		}
		map.y++;
	}
	dimension_map(&map, fd);
	return (map);
}

void	get_x(t_map *map, char *line)
{
	size_t	i;

	i = 0;
	map->x = 2;
	while (i < ft_strlen(line))
	{
		if ((line[i] == ' ' || (9 <= line[i] && line[i] <= 13)) 
		&& (ft_strchr("0123456789+-",line[i + 1])))
			map->x += 1;
		i++;
	}
}

void	dimension_map(t_map *map, int fd)
{
	int	i;
	
	i = 0;
	map->xy = (int **)malloc((map->x)*sizeof(int*));
	while (i < map->x)
	{
		map->xy[i] = (int *)malloc((map->y)*sizeof(int));
		i++;
	}
	close (fd);
}
