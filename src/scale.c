#include "graphic.h"

void calculate_scale(t_map *map)
{
	if ((map->x) > (map->y))
		map->scale = ((X_MED - 10)) / (map->x);
	else
		map->scale =  ((Y_MED - 10)) / (map->y);
}


