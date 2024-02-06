#include "../incl/cub3d.h"

/*int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}*/

int	ft_put_updown(t_data *data)
{
	int	i;
    int j;

    if (data->win_ptr == NULL)
        return (1);
    i = 0;
    while (i < 480/2)
    {
        j = 0;
        while (j < 640)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0xBFEFFF);
        ++i;
    }
	i = 480/2 ;
    while (i < 480/2 + 480/2 )
    {
        j = 0;
        while (j < 640)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0xCDAA7D);
        ++i;
    }
	i = 480 - 80;
    while (i < (480 - 80) + 480/2 )
    {
        j = 0;
        while (j < 120)
		{
			if (i == 480 - 80 || i == 479 || j == 0 || j == 119)
	            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, 0xFFFFFF);
			j++;
		}
        ++i;
    }
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->mini->px, data->mini->py, 0x0000CD);
    return (0);
}

int	ft_put_the_map(t_data *data, char **map)
{
	int	i;
    int j;

    (void)map;
    if (data->win_ptr == NULL)
        return (1);
    i = 14;
    while (i < 480/2)
    {
        j = 0;
        while (j < 640)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0xBFEFFF);
        ++i;
    }
    return (0);
}

int ft_main_act(t_data *data)
{
	ft_put_updown(data);
	ft_put_the_map(data, data->map->map);
    /*while (!done())
    {
        ;
    }*/
    return (0);
}
int	ft_main_loop(t_data *data)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 200, 200, 0x0000CD);
	ft_mini_w(data);
	return (0);
}
