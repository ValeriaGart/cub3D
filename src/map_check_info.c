#include "../incl/cub3d.h"

int	start_check_xpm(char *line)
{
	int	k;

	if (ft_strlen(line) <= 4)
	{
		ft_putstr_fd("Error\nMap info is not a \".xpm\"  file\n", 2);
		return (1);
	}
	k = 0;
	while (line && line[k] != '.')
		k++;
	if (!line || !ft_strnstr(line + k, ".xpm", 4))
	{
		ft_putstr_fd("Error\nMap info is not a \".xpm\"  file\n", 2);
		return (1);
	}
	k += 4;
	while (line && line[k] != '\0')
	{
		if (!ft_isspace(line[k++]))
		{
			ft_putstr_fd("Error\nMap info is not a \".xpm\"  file\n", 2);
			return (1);
		}
	}
	return (0);
}

// int	check_real_map(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map->maps[i])
// 	{
// 		j = 0;
// 		while (map->maps[i][j])
// 		{
// 			if (map->maps[i][j] != '1' && map->maps[i][j] != ' ')
// 			{
// 				if (map->maps[i][j] != '0' && map->maps[i][j] != '1'
// 					&& (map->maps[i][j] != 'N' || map->maps[i][j] != 'S'
// 					|| map->maps[i][j] != 'W' || map->maps[i][j] != 'E'))
// 				{
// 					ft_putstr_fd("Error\nMap is not valid\n", 2);
// 					return (1);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

void	check_direction_name(t_map *map, int *i, int *j)
{
	if (map->sou == NULL && (map->maps[*i][*j] == 'S'
		&& map->maps[*i][(*j) + 1] == 'O'))
		map->sou = ft_strdup(map->maps[*i] + 2);
	else if (map->nor == NULL && (map->maps[*i][*j] == 'N'
		&& map->maps[*i][(*j) + 1] == 'O'))
		map->nor = ft_strdup(map->maps[*i] + 2);
	else if (map->wes == NULL && (map->maps[*i][*j] == 'W'
		&& map->maps[*i][(*j) + 1] == 'E'))
		map->wes = ft_strdup(map->maps[*i] + 2);
	else if (map->eas == NULL && (map->maps[*i][*j] == 'E'
		&& map->maps[*i][(*j) + 1] == 'A'))
		map->eas = ft_strdup(map->maps[*i] + 2);
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
		while (ft_isspace(map->maps[i][j]))
			j++;
		if (check_colour(map, &i, &j))
			return (1);
		check_direction_name(map, &i, &j);
		i++;
	}
	if (map->nor == NULL || map->sou == NULL || map->wes == NULL
		|| map->eas == NULL)
	{
		ft_putstr_fd("Error\nMissing texture path\n", 2);
		return (1);
	}
	return (0);
}

int	check_four_paths(t_map *map)
{
	if (check_path_south(map))
		return (1);
	else if (check_path_north(map))
		return (1);
	else if (check_path_west(map))
		return (1);
	else if (check_path_east(map))
		return (1);
	return (0);
}
