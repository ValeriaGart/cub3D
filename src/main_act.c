#include "../incl/cub3d.h"

//TODO: Yen, store the numbers for me please
/*int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}*/

void    ft_put_img_on_window(t_data *data)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, data->img.img);
    data->img.img = NULL;
}

int	ft_draw_updown(t_img *img, t_data *data)
{
	unsigned int    *ptr;
    unsigned int    i;

    if (data->win_ptr == NULL)
        return (1);
    ptr = (unsigned int *) img->addr;
    i = WIDTH_X * HEIGHT_Y / 2 + 1;
    while (--i > 0)
        *ptr++ =  0xBFEFFF;
    i = WIDTH_X * HEIGHT_Y / 2 + 1;
    while (--i > 0)
        *ptr++ = 0xCDAA7D;
    /* TODO: Yen, i need it for the small window
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
    }*/
    return (0);
}

void	ft_put_the_map(t_data *data, char **map)
{
	int	i;
    int j;

    (void)map;
    if (data->win_ptr == NULL)
        return ;
    i = 14;
    while (i < 480/2)
    {
        j = 0;
        while (j < 640)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0xBFEFFF);
        ++i;
    }
}

int ft_main_act(t_data *data)
{
	ft_draw_updown(&(data->img), data);
    ft_put_img_on_window(data);
    return (0);
}
