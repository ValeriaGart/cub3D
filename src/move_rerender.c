#include "../incl/cub3d.h"

void    ft_move_plr_map(t_map **map, int new_pos_x, int new_pos_y, t_data **data)
{
    int x;
    int y;

    x = (*data)->plr.x;
    y = (*data)->plr.y;
    if (new_pos_x && (*map)->maps[y][x + new_pos_x] == '0')
    {
        (*map)->maps[y][x] = '0';
        if (new_pos_x > 0)
            (*data)->plr.direction = 'E';
        else
            (*data)->plr.direction = 'W';
        (*data)->plr.x = x + new_pos_x;
        (*map)->maps[y][x + new_pos_x] = (*data)->plr.direction;
    }
    if (new_pos_y && (*map)->maps[y + new_pos_y][x] == '0')
    {
        (*map)->maps[y][x] = '0';
        if (new_pos_y > 0)
            (*data)->plr.direction = 'S';
        else
            (*data)->plr.direction = 'N';
        (*data)->plr.y = y + new_pos_y;
        (*map)->maps[y + new_pos_y][x] = (*data)->plr.direction;
    }
}

void	ft_rotate(t_rc *raycast, char direction)
{
	double	oldDirX;
	double	oldPlaneX;
	if (direction == 'l')
	{
		oldDirX = raycast->dirX;
		raycast->dirX = raycast->dirX * cos(0.3) - raycast->dirY * sin(0.3);
		raycast->dirY = oldDirX * sin(0.3) + raycast->dirY * cos(0.3);
		oldPlaneX = raycast->planeX;
		raycast->planeX = raycast->planeX * cos(0.3) - raycast->planeY * sin(0.3);
		raycast->planeY = oldPlaneX * sin(0.3) + raycast->planeY * cos(0.3);
    }
    if (direction == 'r')
	{
		oldDirX = raycast->dirX;
		raycast->dirX = raycast->dirX * cos(-0.3) - raycast->dirY * sin(-0.3);
		raycast->dirY = oldDirX * sin(-0.3) + raycast->dirY * cos(-0.3);
		oldPlaneX = raycast->planeX;
		raycast->planeX = raycast->planeX * cos(-0.3) - raycast->planeY * sin(-0.3);
		raycast->planeY = oldPlaneX * sin(-0.3) + raycast->planeY * cos(-0.3);
	}
}

void    ft_direction_button(char direction, t_data *data, t_rc *raycast)
{
	if (direction == 'l' || direction == 'r')
		ft_rotate(raycast, direction);
    if (direction == 'u')
    {
		if (data->map->real_map[(int)((data->raycast.posY + raycast->dirY
					* 0.3))][(int)(raycast->posX)] == '0')
			raycast->posY += raycast->dirY * 0.3;
		if (data->map->real_map[(int)(raycast->posY)]
				[(int)(raycast->posX + raycast->dirX * 0.3)] == '0')
			raycast->posX += raycast->dirX * 0.3;
	}
    if (direction == 'd')
	{
		if (data->map->real_map[(int)((data->raycast.posY - raycast->dirY
					* 0.3))][(int)(raycast->posX)] == '0')
			raycast->posY -= raycast->dirY * 0.3;
		if (data->map->real_map[(int)(raycast->posY)]
				[(int)(raycast->posX - raycast->dirX * 0.3)] == '0')
			raycast->posX -= raycast->dirX * 0.3;
	}
    if (data->smallw_enabled == true)
        ft_small_w(&data);
}
