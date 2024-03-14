#include "../incl/cub3d.h"

void	ft_move_sides(int keysym, t_data *data)
{
	t_rc	*raycast;

	raycast = &data->raycast;
	if (keysym == XK_d)
	{
		if (data->map->real_map[(int)((data->raycast.pos_y + raycast->dir_x
					* 0.3))][(int)(raycast->pos_x)] == '0')
			raycast->pos_y += raycast->dir_x * 0.3;
		if (data->map->real_map[(int)(data->raycast.pos_y)]
				[(int)(data->raycast.pos_x - raycast->dir_y
				* 0.3)] == '0')
			raycast->pos_x -= raycast->dir_y * 0.3;
	}
	else
	{
		if (data->map->real_map[(int)(data->raycast.pos_y - raycast->dir_x
				* 0.3)][(int)(raycast->pos_x)] == '0')
			raycast->pos_y -= raycast->dir_x * 0.3;
		if (data->map->real_map[(int)(data->raycast.pos_y)]
				[(int)(data->raycast.pos_x + raycast->dir_y
				* 0.3)] == '0')
			raycast->pos_x += raycast->dir_y * 0.3;
	}
	ft_main_act(data);
}

void	ft_rotate(t_rc *raycast, char direction)
{
	double	old_dir_x;
	double	old_plane_x;

	if (direction == 'r')
	{
		old_dir_x = raycast->dir_x;
		raycast->dir_x = raycast->dir_x * cos(0.3) - raycast->dir_y * sin(0.3);
		raycast->dir_y = old_dir_x * sin(0.3) + raycast->dir_y * cos(0.3);
		old_plane_x = raycast->plane_x;
		raycast->plane_x = raycast->plane_x * cos(0.3) - raycast->plane_y
			* sin(0.3);
		raycast->plane_y = old_plane_x * sin(0.3) + raycast->plane_y * cos(0.3);
	}
	if (direction == 'l')
	{
		old_dir_x = raycast->dir_x;
		raycast->dir_x = raycast->dir_x * cos(-0.3) - raycast->dir_y
			* sin(-0.3);
		raycast->dir_y = old_dir_x * sin(-0.3) + raycast->dir_y * cos(-0.3);
		old_plane_x = raycast->plane_x;
		raycast->plane_x = raycast->plane_x * cos(-0.3) - raycast->plane_y
			* sin(-0.3);
		raycast->plane_y = old_plane_x * sin(-0.3) + raycast->plane_y
			* cos(-0.3);
	}
}

void	ft_direction_button(char direction, t_data *data, t_rc *raycast)
{
	if (direction == 'l' || direction == 'r')
		ft_rotate(raycast, direction);
	if (direction == 'u')
	{
		if (data->map->real_map[(int)((data->raycast.pos_y + raycast->dir_y
					* 0.3))][(int)(raycast->pos_x)] == '0')
			raycast->pos_y += raycast->dir_y * 0.3;
		if (data->map->real_map[(int)(raycast->pos_y)][(int)(raycast->pos_x
				+ raycast->dir_x * 0.3)] == '0')
			raycast->pos_x += raycast->dir_x * 0.3;
	}
	if (direction == 'd')
	{
		if (data->map->real_map[(int)((data->raycast.pos_y - raycast->dir_y
					* 0.3))][(int)(raycast->pos_x)] == '0')
			raycast->pos_y -= raycast->dir_y * 0.3;
		if (data->map->real_map[(int)(raycast->pos_y)][(int)(raycast->pos_x
				- raycast->dir_x * 0.3)] == '0')
			raycast->pos_x -= raycast->dir_x * 0.3;
	}
	ft_main_act(data);
}
