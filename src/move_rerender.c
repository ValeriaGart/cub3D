#include "../incl/cub3d.h"

void    ft_move_plr_map(t_map **map, int new_pos_x, int new_pos_y, t_data **data)
{
    int x;
    int y;

    x = (*data)->plr.x;
    y = (*data)->plr.y;
    if (new_pos_x && (*map)->map[y][x + new_pos_x] == '0')
    {
        (*map)->map[y][x] = '0';
        if (new_pos_x > 0)
            (*data)->plr.direction = 'E';
        else
            (*data)->plr.direction = 'W';
        (*data)->plr.x = x + new_pos_x;
        (*map)->map[y][x + new_pos_x] = (*data)->plr.direction;
    }
    if (new_pos_y && (*map)->map[y + new_pos_y][x] == '0')
    {
        (*map)->map[y][x] = '0';
        if (new_pos_y > 0)
            (*data)->plr.direction = 'S';
        else
            (*data)->plr.direction = 'N';
        (*data)->plr.y = y + new_pos_y;
        (*map)->map[y + new_pos_y][x] = (*data)->plr.direction;
    }
}

void    ft_direction_button(char direction, t_data *data)
{
    int new_pos_x;
    int new_pos_y;

    new_pos_x = 0;
    new_pos_y = 0;
    if (direction == 'l')
    {
        //new_pos_x = -1;
        data->plr.angle -= 0.1;
        if (data->plr.angle < 0)
            data->plr.angle += 2 * PI;
        data->plr.delta_x = cos(data->plr.angle) * 5;
        data->plr.delta_y = sin(data->plr.angle) * 5;
    }
    if (direction == 'r')
    {
        //new_pos_x = 1;
        data->plr.angle += 0.1;
        if (data->plr.angle > PI * 2)
            data->plr.angle -= 2 * PI;
        data->plr.delta_x = cos(data->plr.angle) * 5;
        data->plr.delta_y = sin(data->plr.angle) * 5;
    }
    if (direction == 'u')
    {
        new_pos_y -= data->plr.delta_x;
        new_pos_y -= data
    }
    if (direction == 'd')
        new_pos_y = 1;
    ft_move_plr_map(&(data->map), new_pos_x, new_pos_y, &data);
    if (data->smallw_enabled == true)
        ft_small_w(&data);
}
