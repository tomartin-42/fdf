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
		//while (buff_map[j] != NULL)
		while (buff_map[j])
		{
//			printf ("**%s    %d %d**\n", buff_map[j], i ,j);
			map->xy[i][j] = ft_atoi (buff_map[j]);
			get_color(map, buff_map[j],i, j); 
			free (buff_map[j]);
			j++;
		}
		free(buff_map);
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
			printf ("%-4d",map->xy[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	printf("x= %d\ny= %d\n",map->x, map->y);
	printf ("\n");
}

void	get_color(t_map *map, char *str, int i, int j)
{
	int	base;
	int	len;
	int	ini;

	ini = 0;
	if(ft_strchr(str, ','))
	{	
		while (str[ini] != ',' && ini < (int) ft_strlen(str))
			ini++;
		ini = ini + 2;
		base = 1;
		len = ft_strlen(str) - 1;
		while (len > ini)
		{
			if (ft_isdigit(str[len]))
				map->color[i][j] += (str[len] - 48) * base;
			else if (str[len] >= 'A' && str[len] <= 'F')
				map->color[i][j] += (str[len] - 55) * base;
			else if (str[len] >= 'a' && str[len] <= 'f')
				map->color[i][j] += (str[len] - 87) * base;
			base *= 16;
			len--;
		}
	}
	else
		map->color[i][j] = 0x00FFFFFF;
}
