#include "../incl/cub3d.h"

void init_map(t_map *map)
{
    map->ln = NULL;
    map->sou = NULL;
    map->nor = NULL;
    map->eas = NULL;
    map->wes = NULL;
    map->ceil = NULL;
    map->floor = NULL;
    map->ceil_colour = 0;
    map->floor_colour = 0;
    map->x_map = 0;
    map->y_map = 0;
    map->size_list = 0;
    map->fd = 0;
    map->maps = NULL;
    map->real_map = NULL;
}
