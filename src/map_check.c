#include "../incl/cub3d.h"

int ft_store_map(char *av, t_map *map)
{
	char **map;
	int i;
	int y;

	i = 0;
	y = 0;
}

int ft_map_check(char **av, t_data *data)
{
	t_map map;

	if (ft_store_map(av, &map))
		return (1);
	return (0);
}
