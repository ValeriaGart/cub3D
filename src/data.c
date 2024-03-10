#include "../incl/cub3d.h"

void	ft_player_found(t_data *data, t_map *map, int y, int x)
{
	data->plr.x = x + 0.5;
	data->plr.y = y + 0.5;
	data->plr.direction = map->real_map[y][x];
	if (map->real_map[y][x] == 'N')
		data->plr.angle = PI / 2;
	if (map->real_map[y][x] == 'W')
		data->plr.angle = PI;
	if (map->real_map[y][x] == 'S')
		data->plr.angle = 3 * PI / 2;
	map->real_map[y][x] = '0';
}

void	ft_set_plr(t_map *map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->plr.angle = 0;
	while (map->real_map[y])
	{
		x = 0;
		while (map->real_map[y][x])
		{
			if (ft_strchr("NWES", map->real_map[y][x]))
			{
				ft_player_found(data, map, y, x);
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

void	ft_set_data(t_data *data)
{
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->smallw_enabled = true;
	data->raycast.posX = 0;
	data->raycast.posY = 0;
	data->img.img = NULL;
	data->small_w.img = NULL;
	data->ea.img = NULL;
	data->we.img = NULL;
	data->no.img = NULL;
	data->so.img = NULL;
}
