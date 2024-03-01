#include "../incl/cub3d.h"

void    ft_set_plr(t_map *map, t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    data->plr.angle = 0;
    while (map->maps[y])
    {
        x = 0;
        while (map->maps[y][x])
        {
            if (ft_strchr("NWES", map->maps[y][x]))
            {
                data->plr.x = x;
                data->plr.y = y;
                data->plr.direction = map->maps[y][x];
                if (map->maps[y][x] == 'N')
                    data->plr.angle = PI / 2;
                if (map->maps[y][x] == 'W')
                    data->plr.angle = PI;
                if (map->maps[y][x] == 'S')
                    data->plr.angle = 3 * PI / 2;
                return ;
            }
            x++;
        }
        y++;
    }
	data->plr.angle = 0;
    data->plr.delta_x = cos(data->plr.angle) * 5;
	data->plr.delta_y = sin(data->plr.angle) * 5;
}

void ft_set_data(t_data *data)
{
    data->map = NULL;
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->smallw_enabled = true;
	data->raycast.posX = 0;
	data->raycast.posY = 0;
}
