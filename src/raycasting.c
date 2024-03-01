#include "../incl/cub3d.h"

void	ft_hit_where(t_rc *raycast, t_data *data)
{
	while(raycast->hit == 0)
	{
		if(raycast->sideDistX < raycast->sideDistY)
		{
			raycast->sideDistX += raycast->deltaDistX;
			raycast->mapX += raycast->stepX;
			raycast->side = 0;
		}
		else
		{
			raycast->sideDistY += raycast->deltaDistY;
			raycast->mapY += raycast->stepY;
			raycast->side = 1;
		}
		if(data->map->real_map[raycast->mapY][raycast->mapX] > '0')
			raycast->hit = 1;
	}
}

void	ft_step_calc(t_rc *raycast)
{
	if(raycast->rayDirX < 0)
	{
		raycast->stepX = -1;
		raycast->sideDistX = (raycast->posX - raycast->mapX) * raycast->deltaDistX;
	}
	else
	{
		raycast->stepX = 1;
		raycast->sideDistX = (raycast->mapX + 1.0 - raycast->posX) * raycast->deltaDistX;
	}
	if(raycast->rayDirY < 0)
	{
		raycast->stepY = -1;
		raycast->sideDistY = (raycast->posY - raycast->mapY) * raycast->deltaDistY;
	}
	else
	{
		raycast->stepY = 1;
		raycast->sideDistY = (raycast->mapY + 1.0 - raycast->posY) * raycast->deltaDistY;
	}
}

void	ft_calc_put_line(t_rc *raycast, t_data *data, int x)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	int color;

	lineHeight = (int)(HEIGHT_Y / raycast->perpWallDist);
	if (raycast->perpWallDist == 0)
		lineHeight = HEIGHT_Y;
	drawStart = -lineHeight / 2 + HEIGHT_Y / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT_Y / 2;
	if(drawEnd >= HEIGHT_Y)
		drawEnd = HEIGHT_Y - 1;		
	drawStart = x + (drawStart * WIDTH_X);
	drawEnd = drawEnd * WIDTH_X + x;
	if (data->map->real_map[raycast->mapY][raycast->mapX] == '1')
		color = 0XFF0000;
	else
		color = 0XFF0000;
    if(raycast->side == 1) {color = 0X8B0000;}
	ft_drawtheline(drawStart, drawEnd, data ,color);
}

int	ft_raycasting(t_data *data)
{
	t_rc	*raycast;
	int		x;

	raycast = &(data->raycast);
	x = 0;
	while(x < WIDTH_X)
	{
		ft_init_raycast_loop(data, x);
		ft_step_calc(&(data->raycast));
		ft_hit_where(&(data->raycast), data);
    	if(raycast->side == 0)	raycast->perpWallDist = (raycast->sideDistX - raycast->deltaDistX);
    	else			raycast->perpWallDist = (raycast->sideDistY - raycast->deltaDistY);
		ft_calc_put_line(&(data->raycast), data, x);
		x++;
	}
	return (0);
}
