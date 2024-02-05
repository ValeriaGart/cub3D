#include "../incl/cub3d.h"

// TODO: change win_ptr params to correct width and height
int ft_open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (ft_putstr_fd("Error\nMlx_init failed\n", 2), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 640,
								   480, "Cub3D");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (ft_putstr_fd("Error\nMlx_init failed\n", 2), 1);
	}
	return (0);
}
