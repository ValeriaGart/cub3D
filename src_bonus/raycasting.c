/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:40:12 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/21 17:44:48 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_check_side_hit(t_rc *raycast)
{
	if (raycast->side_dist_x < raycast->side_dist_y)
	{
		raycast->side_dist_x += raycast->delta_dist_x;
		raycast->map_x += raycast->step_x;
		raycast->side = 0;
	}
	else
	{
		raycast->side_dist_y += raycast->delta_dist_y;
		raycast->map_y += raycast->step_y;
		raycast->side = 1;
	}
}

void	ft_hit_where(t_rc *raycast, t_data *data)
{
	while (raycast->hit == 0)
	{
		ft_check_side_hit(raycast);
		if ((raycast->map_x < 0 || raycast->map_x > data->map->x_map - 1)
			|| (raycast->map_y < 0 || raycast->map_y > data->map->y_map - 1))
		{
			raycast->perpwalldist = __DBL_MAX__;
			raycast->lineheight = (int)(HEIGHT_Y / raycast->perpwalldist);
			return ;
		}
		if (data->map->real_map[raycast->map_y][raycast->map_x] > '0')
			raycast->hit = 1;
	}
	if (!raycast->side)
		raycast->perpwalldist = (raycast->side_dist_x - raycast->delta_dist_x);
	else
		raycast->perpwalldist = (raycast->side_dist_y - raycast->delta_dist_y);
	raycast->lineheight = (int)(HEIGHT_Y / raycast->perpwalldist);
}

void	ft_step_calc(t_rc *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (raycast->pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - raycast->pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (raycast->pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - raycast->pos_y)
			* raycast->delta_dist_y;
	}
}

void	ft_calc_put_line(t_rc *raycast, t_data *data, int x)
{
	int	draw_start;
	int	draw_end;

	draw_start = -raycast->lineheight / 2 + HEIGHT_Y / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = raycast->lineheight / 2 + HEIGHT_Y / 2;
	if (draw_end >= HEIGHT_Y)
		draw_end = HEIGHT_Y - 1;
	draw_start = x + (draw_start * WIDTH_X);
	draw_end = draw_end * WIDTH_X + x;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		raycast->what_side = 0;
	else if (!raycast->side && raycast->ray_dir_x > 0)
		raycast->what_side = 1;
	else if (raycast->side && raycast->ray_dir_y > 0)
		raycast->what_side = 2;
	else
		raycast->what_side = 3;
	ft_draw_pic(draw_start, draw_end, data, x);
}

int	ft_raycasting(t_data *data)
{
	int		x;

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
