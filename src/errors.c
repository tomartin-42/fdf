/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:00:08 by tommy             #+#    #+#             */
/*   Updated: 2021/08/31 21:00:10 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphic.h"

void	execut_error(char *s, int errornum)
{
	printf("%s\n", s);
	exit(errornum);
}

void	freeall(t_map *map)
{
	int	i;
	int	j;

	i = map->x - 1;
	j = map->y - 1;
	while (i >= 0)
	{
		free(map->xy[i]);
		free(map->color[i]);
		i--;
	}
	free(map->xy);
	free(map->color);
}
