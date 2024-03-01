#include "../incl/cub3d.h"

void	ft_fill_spaces(char **map, int i, t_map *maps)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (ft_isspace(map[i][j]))
			map[i][j] = '1';
		j++;
	}
	while (j < maps->x_map)
	{
		map[i][j] = '1';
		j++;
	}
}

int	ft_square_map(char **map, t_map *maps, t_data *data)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (map[i])
	{
		new = map[i];
		map[i] = ft_calloc(sizeof(char), maps->x_map + 1);
		if (!map[i])
			return (1);
		ft_strlcpy(map[i], new, ft_strlen(new));
		free(new);
		ft_fill_spaces(map, i, maps);
		i++;
	}
	data->map->real_map = map;
	return (0);
}

void	ft_put_pixel_raycast(t_data *data, int colour, int z)
{
	int	offset;

	offset = z * 4;
	*((unsigned int *)(offset + (&(data->img))->addr)) = colour;
}

void	ft_drawtheline(int x, int y, t_data *data, int colour)
{