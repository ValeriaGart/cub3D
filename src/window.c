#include "../incl/cub3d.h"

int	ft_new_img(t_data *data, t_img *img, int x, int y)
{
	img->img = mlx_new_image(data->mlx_ptr, x, y);
	if (!img->img)
		return (ft_putstr_fd("Error\nMlx image creation failed\n", 2), 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	return (0);
}

int	ft_open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (ft_putstr_fd("Error\nMlx_init failed\n", 2), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH_X, HEIGHT_Y, "Cub3D");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (ft_putstr_fd("Error\nMlx window creating failed", 2), 1);
	}
	return (0);
}
