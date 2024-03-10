#include "../incl/cub3d.h"

void	save_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	*ft_map_free(t_map *map)
{
	int	i;

	i = -1;
	save_free((void **)&map->nor);
	save_free((void **)&map->sou);
	save_free((void **)&map->wes);
	save_free((void **)&map->eas);
	save_free((void **)&map->ceil);
	save_free((void **)&map->floor);
	if (map->maps)
	{
		while (++i < map->size_list && map->maps[i])
			save_free((void **)&map->maps[i]);
		save_free((void **)&map->maps);
	}
	if (map->real_map)
	{
		i = -1;
		while (map->real_map[++i])
			save_free((void **)&map->real_map[i]);
		save_free((void **)&map->real_map);
	}
	save_free((void **)&map);
	return (NULL);
}

int	ft_destroy_textures(t_data *data)
{
	if (data->ea.img)
		mlx_destroy_image(data->mlx_ptr, data->ea.img);
	data->ea.img = NULL;
	if (data->we.img)
		mlx_destroy_image(data->mlx_ptr, data->we.img);
	data->we.img = NULL;
	if (data->no.img)
		mlx_destroy_image(data->mlx_ptr, data->no.img);
	data->no.img = NULL;
	if (data->so.img)
		mlx_destroy_image(data->mlx_ptr, data->so.img);
	data->so.img = NULL;
	return (1);
}

int	ft_free_window(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->win_ptr, data->img.img);
	ft_destroy_textures(data);
	if (data->small_w.img)
		mlx_destroy_image(data->win_ptr, data->small_w.img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	return (1);
}

int	ft_free_all(t_data *data)
{
	ft_map_free(data->map);
	return (ft_free_window(data));
}
