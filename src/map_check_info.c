#include "../incl/cub3d.h"

void	check_direction_name(t_map *map, int *i, int *j)
{
	if (map->sou == NULL && (map->maps[*i][*j] == 'S'
		&& map->maps[*i][(*j) + 1] == 'O'))
		map->sou = ft_strdup(map->maps[*i] + 1);
	else if (map->nor == NULL && (map->maps[*i][*j] == 'N'
		&& map->maps[*i][(*j) + 1] == 'O'))
		map->nor = ft_strdup(map->maps[*i] + 1);
	else if (map->wes == NULL && (map->maps[*i][*j] == 'W'
		&& map->maps[*i][(*j) + 1] == 'E'))
		map->wes = ft_strdup(map->maps[*i] + 1);
	else if (map->eas == NULL && (map->maps[*i][*j] == 'E'
		&& map->maps[*i][(*j) + 1] == 'A'))
		map->eas = ft_strdup(map->maps[*i] + 1);
}

int	check_inforhead(t_map *map, int i, int j)
{
	while (i < map->size_list - 1 && map->maps[i] != NULL)
	{
		if (map->maps[i][0] == '\n')
		{
			i++;
			continue ;
		}
		j = 0;
		while (map->maps[i][j] && ft_isspace(map->maps[i][j]))
			j++;
		if (check_colour(map, &i, &j))
			return (1);
		check_direction_name(map, &i, &j);
		i++;
	}
	if (map->nor == NULL || map->sou == NULL || map->wes == NULL
		|| map->eas == NULL || map->ceil == NULL || map->floor == NULL)
	{
		ft_putstr_fd("Error\nMissing texture path\n", 2);
		return (1);
	}
	return (0);
}
