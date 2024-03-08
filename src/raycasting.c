#include "../incl/cub3d.h"

void	ft_check_side_hit(t_rc *raycast)
{
	if (raycast->sideDistX < raycast->sideDistY)
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
}

void	ft_hit_where(t_rc *raycast, t_data *data)
{
	while (raycast->hit == 0)
	{
		ft_check_side_hit(raycast);
		if ((raycast->mapX < 0 || raycast->mapX > data->map->x_map - 1)
			|| (raycast->mapY < 0 || raycast->mapY > data->map->y_map - 1))
		{
			raycast->perpWallDist = __DBL_MAX__;
			raycast->lineheight = (int)(HEIGHT_Y / raycast->perpWallDist);
			return ;
		}
		if (data->map->real_map[raycast->mapY][raycast->mapX] > '0')
			raycast->hit = 1;
	}
	if (!raycast->side)
		raycast->perpWallDist = (raycast->sideDistX - raycast->deltaDistX);
	else
		raycast->perpWallDist = (raycast->sideDistY - raycast->deltaDistY);
	raycast->lineheight = (int)(HEIGHT_Y / raycast->perpWallDist);
}

void	ft_step_calc(t_rc *raycast)
{
	if (raycast->rayDirX < 0)
	{
		raycast->stepX = -1;
		raycast->sideDistX = (raycast->posX - raycast->mapX)
			* raycast->deltaDistX;
	}
	else
	{
		raycast->stepX = 1;
		raycast->sideDistX = (raycast->mapX + 1.0 - raycast->posX)
			* raycast->deltaDistX;
	}
	if (raycast->rayDirY < 0)
	{
		raycast->stepY = -1;
		raycast->sideDistY = (raycast->posY - raycast->mapY)
			* raycast->deltaDistY;
	}
	else
	{
		raycast->stepY = 1;
		raycast->sideDistY = (raycast->mapY + 1.0 - raycast->posY)
			* raycast->deltaDistY;
	}
}

void	ft_calc_put_line(t_rc *raycast, t_data *data, int x)
{
	int	draw_start;
	int	draw_end;
	int	color;

	color = 0;
	draw_start = -raycast->lineheight / 2 + HEIGHT_Y / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = raycast->lineheight / 2 + HEIGHT_Y / 2;
	if (draw_end >= HEIGHT_Y)
		draw_end = HEIGHT_Y - 1;
	draw_start = x + (draw_start * WIDTH_X);
	draw_end = draw_end * WIDTH_X + x;
	if (raycast->side == 1 && raycast->rayDirY < 0)
		raycast->what_side = 0;
	else if (!raycast->side && raycast->rayDirX > 0)
		raycast->what_side = 1;
	else if (raycast->side && raycast->rayDirY > 0)
		raycast->what_side = 2;
	else
		raycast->what_side = 3;
	ft_draw_pic(draw_start, draw_end, data, color, x);
}

int	ft_raycasting(t_data *data)
{
	t_rc	*raycast;
	int		x;

	raycast = &(data->raycast);
	x = 0;
	while (x < WIDTH_X)
	{
		ft_init_raycast_loop(data, x);
		ft_step_calc(&(data->raycast));
		ft_hit_where(&(data->raycast), data);
		ft_calc_put_line(&(data->raycast), data, x);
		x++;
	}
	return (0);
}
