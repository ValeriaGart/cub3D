#include "../incl/cub3d.h"

int init_map(t_map *map)
{
    map->NO = NULL;
    map->SO = NULL;
    map->EA = NULL;
    map->WE = NULL;
    map->path = NULL;
    map->up_colour = NULL;
    map->down_colour = NULL;
    map->map = NULL;
    return (0);
}
