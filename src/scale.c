#include "graphic.h"

void calculate_scale(t_map *map)
{
	if ((map->x / 2) > (map->y / 2))
		map->scale = ((X_MED - 10)) / (map->x / 2);
	else
		map->scale =  ((Y_MED - 10)) / (map->y / 2);
}
