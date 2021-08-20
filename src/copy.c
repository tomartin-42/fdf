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
			map->color[i][j] = copy_colors(buff_map[j]); 
			free (buff_map[j]);
			j++;
		}
		free(buff_map);
		i++;
	}
}

int	copy_colors(char *string)
{
	int	i;
	int	color;

	color = 0x00FF00FF;	
	i = 0;
	while(string[i])
	{
		if(string[i] != ',')
			i++;
		else
		{
			color = exatoi(string, i);
			//printf ("%X\n", color);
			break ;
		}
	}
	return (color);
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

int	exatoi(char *hex, int i)
{
	int	color;
   	int	y;
	int	x;
	int	j;
	
	j = i + 3;
	color = 0;
	y = 0;
	while (hex[i] != '\0')
		i++;
	while(i >= j)
	{
      		if(hex[i]>='0' && hex[i]<='9')
         		x = hex[i] - '0';
      		else
         		x = hex[i] - 'A' + 10;
		color = (color * 16) + x;
		//printf("OOO%dOOOO\n", color);
		i--;
	}
   return (color);
}
		
