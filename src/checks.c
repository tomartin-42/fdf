#include "graphic.h"

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

//calculate numbers per line and check if the map is a square
static void	get_y(t_map *map, char *line, int *check)
{
	size_t	i;

	i = 0;
	map->y = 0;
	while (i < ft_strlen(line))
	{
		if ((ft_isalnum(line[i])) && (ft_strchr(" ",line[i + 1])))
			map->y += 1;
		i++;
	}
	if (*check == -1)
		*check = map->y;
	else	
		if (*check != map->y)
			execut_error();
}

//check correct characters and call other functions
t_map	check_fd_map(int fd)
{
	char	*line;
	t_map	map;
	int	check;

	check = -1;
	map.x = 0;
	while (get_next_line(fd, &line))
	{
		get_y(&map, line, &check);
		free(line);
		map.x++;
	}
	free(line);
	dimension_map(&map, fd);
	return (map);
}

//size matrix
void	dimension_map(t_map *map, int fd)
{
	int	i;
	
	i = 0;
	map->xy = (int **)malloc((map->x)*sizeof(int*));
	map->color = (int **)malloc((map->x)*sizeof(int*));
	while (i < map->x)
	{
		map->xy[i] = (int *)malloc((map->y)*sizeof(int));
		map->color[i] = (int *)malloc((map->y)*sizeof(int));
		i++;
	}
	map->scale = 2;
	close (fd);
}
