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

void    ft_direction_button(char direction, t_data *data, t_rc *raycast)
{
    float new_pos_x;
    float new_pos_y;
	//double moveSpeed = 30 * 5.0;

    new_pos_x = 0;
    new_pos_y = 0;
    if (direction == 'l')
    {
		double oldDirX = raycast->dirX;
    	raycast->dirX = raycast->dirX * cos(0.3) - raycast->dirY * sin(0.3);
    	raycast->dirY = oldDirX * sin(0.3) + raycast->dirY * cos(0.3);
    	double oldPlaneX = raycast->planeX;
    	raycast->planeX = raycast->planeX * cos(0.3) - raycast->planeY * sin(0.3);
    	raycast->planeY = oldPlaneX * sin(0.3) + raycast->planeY * cos(0.3);
    }
    if (direction == 'r')
    {
		double oldDirX = raycast->dirX;
    	raycast->dirX = raycast->dirX * cos(-0.3) - raycast->dirY * sin(-0.3);
    	raycast->dirY = oldDirX * sin(-0.3) + raycast->dirY * cos(-0.3);
    	double oldPlaneX = raycast->planeX;
    	raycast->planeX = raycast->planeX * cos(-0.3) - raycast->planeY * sin(-0.3);
    	raycast->planeY = oldPlaneX * sin(-0.3) + raycast->planeY * cos(-0.3);
    }
    if (direction == 'u')
    {
		raycast->posX += raycast->dirX * 0.3;
		raycast->posY += raycast->dirY * 0.3;
	}
    if (direction == 'd')
	{
		raycast->posX -= raycast->dirX * 0.3;
		raycast->posY -= raycast->dirY * 0.3;
	}
    ft_move_plr_map(&(data->map), new_pos_x, new_pos_y, &data);
    if (data->smallw_enabled == true)
        ft_small_w(&data);
}
