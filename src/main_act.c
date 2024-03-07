#include "../incl/cub3d.h"

void	ft_put_pixel_small(t_data *data, int x, int y, int colour)
{
	int	offset;

	offset = 400;
	(void)y;
	(void)x;
	/*offset = ((y * WIDTH_SMALL) + x) * 4;//y * ((WIDTH_SMALL * 2)
		+ (HEIGHT_SMALL * 2)) + (x * (data->small_w.bits_per_pixel / 8));
	offset = (y * (HEIGHT_SMALL / data->map->y_map)) * (x * (WIDTH_SMALL
				/ data->map->x_map));
	*((unsigned int *)(offset + (&(data->small_w))->addr)) = colour;*/
	*((unsigned int *)(offset + (&(data->small_w))->addr)) = colour;
}

void	ft_put_img_on_window(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, x, y);
	mlx_destroy_image(data->mlx_ptr, img->img);
	img->img = NULL;
}

int	ft_is_not_empty(int cur_pix, t_data *data)
{
	int		x;
	int		y;
	int		gridColumns;
	int		gridRows;
	float	gridCellWidth;
	float	gridCellHeight;
	int		xPos;
	int		yPos;

	gridColumns = data->map->x_map;
	gridRows = data->map->y_map;
	gridCellWidth = (float)WIDTH_SMALL / gridColumns;
	gridCellHeight = (float)HEIGHT_SMALL / gridRows;
	xPos = cur_pix % WIDTH_SMALL;
	yPos = cur_pix / WIDTH_SMALL;
	x = (int)(xPos / gridCellWidth);
	y = (int)(yPos / gridCellHeight);
	if (ft_strchr("NWSE", data->map->real_map[y][x]))
		return (0xFFFFFF);
	if (data->map->real_map[y][x] != '0')
	{
		return (0x000000);
	}
	return (0xFFFFFF);
}

void	ft_small_w(t_data **data)
{
	unsigned int	*ptr;
	unsigned int	i;
	unsigned int	n;

	ft_new_img(*data, &(*data)->small_w, WIDTH_SMALL, HEIGHT_SMALL);
	ptr = (unsigned int *)(&((*data)->small_w))->addr;
	i = WIDTH_SMALL * HEIGHT_SMALL + 1;
	n = 0;
	while (--i > 0)
	{
		*ptr++ = ft_is_not_empty(n, *data);
		n++;
	}
	ft_put_pixel_small(*data, (*data)->plr.x * (WIDTH_SMALL
			/ (*data)->map->x_map), (*data)->plr.y * (HEIGHT_SMALL
			/ (*data)->map->y_map), 0xEE4B2B);
	ft_put_img_on_window(*data, &(*data)->small_w, 0, (HEIGHT_Y / 4) * 3);
}

int	ft_draw_updown(t_img *img, t_data *data)
{
	unsigned int	*ptr;
	unsigned int	i;

	(void)img;
	if (data->win_ptr == NULL)
		return (1);
	ptr = (unsigned int *)data->img.addr;
	i = WIDTH_X * HEIGHT_Y / 2 + 1;
	while (--i > 0)
		*ptr++ = 0xBFEFFF;
	i = WIDTH_X * HEIGHT_Y / 2 + 1;
	while (--i > 0)
		*ptr++ = 0xCDAA7D;
	return (0);
}

int	ft_put_the_map(t_data *data, char **map)
{
	int	i;
	int	j;

	(void)map;
	if (data->win_ptr == NULL)
		return (0);
	i = 14;
	while (i < 480 / 2)
	{
		j = 0;
		while (j < 640)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x880808);
		++i;
	}
	return (0);
}

int	ft_main_act(t_data *data)
{
	ft_new_img(data, &data->img, WIDTH_X, HEIGHT_Y);
	ft_draw_updown(&(data->img), data);
	ft_raycasting(data);
	ft_put_img_on_window(data, &(data->img), 0, 0);
	// if (data->smallw_enabled == true)
	//    ft_small_w(&data);
	return (0);
}
