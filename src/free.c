#include "../incl/cub3d.h"

void	*ft_map_free(t_map *map)
{
	int i;

	i = -1;
	if (map->nor)
		free(map->nor);
	if (map->sou)
		free(map->sou);
	if (map->wes)
		free(map->wes);
	if (map->eas)
		free(map->eas);
	if (map->ceil)
		free(map->ceil);
	if (map->floor)
		free(map->floor);
	if (map->map)
	{
		while (map->map[++i])
				free(map->map[i]);
		free(map->map);
	}
	if (map)
		free(map);
	return (NULL);
}

int ft_free_window(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->img.img)
		mlx_destroy_image(data->win_ptr, data->img.img);
	return (1);
}

int ft_free_all(t_data *data)
{
	ft_map_free(data->map);
	return (ft_free_window(data));
}
