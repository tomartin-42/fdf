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

void	check_fd_map(int fd)
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
			if (!ft_strchr("0123456789 +-\t", line[i]))
				execut_error();
			i++;
		}
		if  (ft_strlen(line) > 0)
			get_x (&map, line);
		map.y++;
	}
	printf ("[[%d - %d]]\n",map.x, map.y);
}

void	get_x (t_map *map, char *line)
{
	size_t	i;

	i = 0;
	map->x = 1;
	while (i < ft_strlen(line))
	{
		if ((line[i] == ' ' || (9 <= line[i] && line[i] <= 13)) && (ft_isalnum(line[i + 1])))
		{
			printf("HOLA - %d - %s-\n",map->x, line);
			map->x += 1;
		}
		i++;
	}
}
	
