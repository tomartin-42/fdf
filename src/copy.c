/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:59:59 by tommy             #+#    #+#             */
/*   Updated: 2021/08/31 21:00:00 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	copy_to_map(t_map *map, char *argv)
{
	int		fd;
	char	*line;
	char	**buff_map;
	int		i;
	int		j;

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
			get_color(map, buff_map[j], i, j);
			free (buff_map[j]);
			j++;
		}
		free(line);
		free(buff_map);
		i++;
	}
	close(fd);
}

//get color and copy in the struct
void	get_color(t_map *map, char *str, int i, int j)
{
	t_caux	aux;

	aux.ini = 0;
	map->color[i][j] = 0;
	if (ft_strchr(str, ','))
	{	
		while (str[aux.ini] != ',' && aux.ini < (int) ft_strlen(str))
			aux.ini++;
		aux.ini = aux.ini + 2;
		aux.base = 1;
		aux.len = ft_strlen(str) - 1;
		while (aux.len > aux.ini)
		{
			if (ft_isdigit(str[aux.len]))
				map->color[i][j] += (str[aux.len] - 48) * aux.base;
			else if (str[aux.len] >= 'A' && str[aux.len] <= 'F')
				map->color[i][j] += (str[aux.len] - 55) * aux.base;
			else if (str[aux.len] >= 'a' && str[aux.len] <= 'f')
				map->color[i][j] += (str[aux.len] - 87) * aux.base;
			aux.base *= 16;
			aux.len--;
		}
	}
	else
		map->color[i][j] = 0x00FFFFFF;
}
