#include "graphic.h"

void	copy_to_map(t_map *map, char *argv)
{
	int	fd;
	char	*line;
	char	**buff_map;
	int	i;
	int	j;

	i = 0;
	fd = open (argv, O_RDONLY);
	//while (i < map->x - 1)
	while (get_next_line(fd, &line))
	{
		//get_next_line (fd, &line);
		buff_map = ft_split (line, ' ');
		j = 0;
		while (buff_map[j])
		{	
			map->xy[i][j] = ft_atoi (buff_map[j]);
			free (buff_map[j]);
			j++;
		}
		i++;
	}
}

void printmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x)
	{	
		j = 0;
		while (j < map->y)
		{
			printf ("%d ",map->xy[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	printf("x= %d\ny= %d\n",map->x, map->y);
	printf ("\n");
}

