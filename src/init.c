#include "../incl/cub3d.h"

void	ft_init_raycast_loop(t_data *data, int x)
{
	data->raycast.cameraX = ((2 * x) / (double)WIDTH_X) - 1;
	data->raycast.rayDirX = data->raycast.dirX + data->raycast.planeX
		* data->raycast.cameraX;
	data->raycast.rayDirY = data->raycast.dirY + data->raycast.planeY
		* data->raycast.cameraX;
	data->raycast.mapX = (int)data->raycast.posX;
	data->raycast.mapY = (int)data->raycast.posY;
	if (data->raycast.rayDirX == 0)
		data->raycast.deltaDistX = __DBL_MAX__;
	else
		data->raycast.deltaDistX = fabs(1.0 / data->raycast.rayDirX);
	if (data->raycast.rayDirY == 0)
		data->raycast.deltaDistY = __DBL_MAX__;
	else
		data->raycast.deltaDistY = fabs(1.0 / data->raycast.rayDirY);
	data->raycast.hit = 0;
	data->raycast.perpWallDist = 0;
}

void	ft_init_raycast(t_data *data)
{
	if (data->raycast.posX == 0)
		data->raycast.posX = data->plr.x;
	if (data->raycast.posY == 0)
		data->raycast.posY = data->plr.y;
	data->raycast.dirX = -1;
	data->raycast.dirY = 0;
	data->raycast.planeX = 0;
	data->raycast.planeY = 0.66;
}

void	init_map(t_map *map)
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
