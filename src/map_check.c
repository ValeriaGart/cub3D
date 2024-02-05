#include "../incl/cub3d.h"

void	ft_put_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

int ft_map_check(char **av, t_data *data)
{
	t_map *map;

	data->line_num = 14;
	map = ft_store_map(av, data);
	if (!map)
		return (1);
	ft_put_map(map->map);
	data->map = map;
	return (0);
}
