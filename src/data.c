#include "../incl/cub3d.h"

void    ft_set_plr(t_map *map, t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    data->plr.angle = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            if (ft_strchr("NWES", map->map[y][x]))
            {
                data->plr.x = x;
                data->plr.y = y;
                data->plr.direction = map->map[y][x];
                if (map->map[y][x] == 'N')
                    data->plr.angle = PI / 2;
                if (map->map[y][x] == 'W')
                    data->plr.angle = PI;
                if (map->map[y][x] == 'S')
                    data->plr.angle = 3 * PI / 2;
                return ;
            }
            x++;
        }
        y++;
    }
    
}

void ft_set_data(t_data *data)
{
    data->map = NULL;
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->smallw_enabled = true;
}
