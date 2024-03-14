#include "../incl/cub3d.h"

void	ft_put_pixel_small(t_data *data, double x, double y, int colour)
{
	int	offset;
	int	ix;
	int	iy;

	x *= 10;
	y *= 10;
	ix = (int)x;
	iy = (int)y;
	x = (float)ix;
	y = (float)iy;
	x /= 10;
	y /= 10;
	iy = (int)(y * (HEIGHT_SMALL / data->map->y_map));
	ix = (int)(x * (WIDTH_SMALL / data->map->x_map));
	offset = (iy * WIDTH_SMALL + ix) * 4;
	*((unsigned int *)((int)offset + (&(data->small_w))->addr)) = colour;
	*((unsigned int *)((int)(offset + 1) + (&(data->small_w))->addr)) = colour;
	offset -= (WIDTH_SMALL * 4);
	*((unsigned int *)((int)offset + (&(data->small_w))->addr)) = colour;
	*((unsigned int *)((int)(offset + 1) + (&(data->small_w))->addr)) = colour;
}

int	ft_is_not_empty(int cur_pix, t_data *data)
{
	float	grid_cell_width;
	float	grid_cell_height;
	int		x_pos;
	int		y_pos;

	grid_cell_width = (float)WIDTH_SMALL / data->map->x_map;
	grid_cell_height = (float)HEIGHT_SMALL / data->map->y_map;
	x_pos = (cur_pix % WIDTH_SMALL) / grid_cell_width;
	y_pos = (cur_pix / WIDTH_SMALL) / grid_cell_height;
	if (ft_strchr("NWSE", data->map->real_map[y_pos][x_pos]))
		return (0xFFFFFF);
	if (data->map->real_map[y_pos][x_pos] != '0')
		return (0x000000);
	return (0xFFFFFF);
}

void	ft_small_w(t_data **data)
{
	unsigned int	*ptr;
	unsigned int	i;
	unsigned int	n;

	if (ft_new_img(*data, &(*data)->small_w, WIDTH_SMALL, HEIGHT_SMALL))
		ft_emergency_exit(*data);
	ptr = (unsigned int *)(&((*data)->small_w))->addr;
	i = WIDTH_SMALL * HEIGHT_SMALL + 1;
	n = 0;
	while (--i > 0)
	{
		*ptr++ = ft_is_not_empty(n, *data);
		n++;
	}
	ft_put_pixel_small(*data, (*data)->raycast.pos_x,
		(*data)->raycast.pos_y, 0xEE4B2B);
}

int	ft_draw_updown(t_data *data)
{
	unsigned int	*ptr;
	unsigned int	i;

	if (data->win_ptr == NULL)
		return (1);
	ptr = (unsigned int *) data->img.addr;
	i = WIDTH_X * HEIGHT_Y / 2 + 1;
	while (--i > 0)
		*ptr++ = data->map->ceil_colour;
	i = WIDTH_X * HEIGHT_Y / 2 + 1;
	while (--i > 0)
		*ptr++ = data->map->floor_colour;
	return (0);
}

int	ft_main_act(t_data *data)
{
	if (ft_new_img(data, &data->img, WIDTH_X, HEIGHT_Y))
		ft_emergency_exit(data);
	ft_draw_updown(data);
	ft_raycasting(data);
	ft_small_w(&data);
	ft_put_img_on_window(data, &(data->img), 0, 0);
	if (data->smallw_enabled == true)
		ft_put_img_on_window(data, &(data->small_w), 0, (HEIGHT_Y / 4) * 3);
	else
	{
		mlx_destroy_image(data->mlx_ptr, data->small_w.img);
		data->small_w.img = NULL;
	}
	return (0);
}
