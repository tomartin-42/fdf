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
		while (buff_map[j] != NULL)
		{
			printf ("**%s**\n", buff_map[j]);
			map->xy[i][j] = ft_atoi (buff_map[j]);
			map->color[i][j] = get_color(buff_map[j]); 
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

static int	get_idx(const char *base, char a)
{
	int	idx;
	int	out;

	out = -1;
	idx = 0;
	while (base[idx])
	{
		if (base[idx] == a)
			out = idx;
		idx++;
	}
	return (out);
}

static char	*get_str_in_lowercase(char **s, int start, size_t len)
{
	char	*out;
	char	*aux;

	aux = ft_substr(*s, start, len + 1);
	out = aux;
	while (*aux)
	{
		*aux = ft_tolower(*aux);
		aux++;
	}
	return (out);
}

int	get_color(char *str)
{
	int		color;
	char	*aux;
	char	*aux_free;
	int		power;

	while(*str++ != ',')
	if (*str != ',')
		return (0xFFFFFF);
	power = 5;
	aux = get_str_in_lowercase(&str, 3, 6);
	aux_free = aux;
	color = 0;
	while (*aux)
		color = color
			+ (int)(get_idx("0123456789abcdef", *aux++) * pow(16, power--));
	free(aux_free);
	return (color);
}
