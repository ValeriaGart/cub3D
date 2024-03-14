#include "../incl/cub3d.h"

void	ft_init_raycast_loop(t_data *data, int x)
{
	data->raycast.camera_x = ((2 * x) / (double)WIDTH_X) - 1;
	data->raycast.ray_dir_x = data->raycast.dir_x + data->raycast.plane_x
		* data->raycast.camera_x;
	data->raycast.ray_dir_y = data->raycast.dir_y + data->raycast.plane_y
		* data->raycast.camera_x;
	data->raycast.map_x = (int)data->raycast.pos_x;
	data->raycast.map_y = (int)data->raycast.pos_y;
	if (data->raycast.ray_dir_x == 0)
		data->raycast.delta_dist_x = __DBL_MAX__;
	else
		data->raycast.delta_dist_x = fabs(1.0 / data->raycast.ray_dir_x);
	if (data->raycast.ray_dir_y == 0)
		data->raycast.delta_dist_y = __DBL_MAX__;
	else
		data->raycast.delta_dist_y = fabs(1.0 / data->raycast.ray_dir_y);
	data->raycast.hit = 0;
	data->raycast.perpwalldist = 0;
}

void	ft_init_raycast(t_data *data)
{
	if (data->raycast.pos_x == 0)
		data->raycast.pos_x = data->plr.x;
	if (data->raycast.pos_y == 0)
		data->raycast.pos_y = data->plr.y;
	data->raycast.plane_x = 0.66 * (data->raycast.dir_x
			* cos(0.5 * 3.14) - data->raycast.dir_y * sin(0.5 * 3.14));
	data->raycast.plane_y = 0.66 * (data->raycast.dir_x
			* sin(0.5 * 3.14) + data->raycast.dir_y * cos(0.5 * 3.14));
}

void	init_map(t_map *map)
{
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
