#include "../incl/cub3d.h"

void	ft_free_all(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
}
