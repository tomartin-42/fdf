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
	while (i < map->x)
	{
		get_next_line(fd, &line);
		buff_map = ft_split (line, ' ');
		j = 0;
		while (buff_map[j])
		{
			map->xy[i][j] = ft_atoi (buff_map[j]);
			free (buff_map[j]);
			j++;
		}
		free(buff_map);
		i++;
	}
}

int	copy_colors(t_map *map, char *string)
{
	char	**buff_color;
	int	i;
	int	color;

	color = 0x00FFFFFF;	
	i = 0;
	while(string[i])
	{
		if(string[i] != ',')
			i++;
		else
			color = exatoi(string, i);
	}
}

void printmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x + 1)
	{
		j = 0;
		while (j < map->y + 1)
		{
			printf ("%-4d",map->xy[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	printf("x= %d\ny= %d\n",map->x, map->y);
	printf ("\n");
}

