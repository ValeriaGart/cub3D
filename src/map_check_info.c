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

int	check_real_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != ' ')
			{
				if (map->map[i][j] != '0' && map->map[i][j] != '1'
					&& (map->map[i][j] != 'N' || map->map[i][j] != 'S'
					|| map->map[i][j] != 'W' || map->map[i][j] != 'E'))
				{
					ft_putstr_fd("Error\nMap is not valid\n", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

//C for color, F for floor, sou for south, nor for north, wes for west, eas for east
int	check_inforhead(t_map *map)
{
	while (1)
	{
		map->ln = get_next_line(map->fd, 0);
		if (map->ln == NULL)
			break ;
		if (check_colour(map))
			return (1);
		if (map->sou == NULL && (map->ln[0] == 'S' && map->ln[1] == 'O'))
			map->sou = ft_strdup(map->ln + 2);
		if (map->nor == NULL && (map->ln[0] == 'N' && map->ln[1] == 'O'))
			map->nor = ft_strdup(map->ln + 2);
		if (map->wes == NULL && (map->ln[0] == 'W' && map->ln[1] == 'E'))
			map->wes = ft_strdup(map->ln + 2);
		if (map->eas == NULL && (map->ln[0] == 'E' && map->ln[1] == 'A'))
			map->eas = ft_strdup(map->ln + 2);
	}
	if (map->nor == NULL || map->sou == NULL || map->wes == NULL
		|| map->eas == NULL)
	{
		ft_putstr_fd("Error\nMissing texture path\n", 2);
		return (1);
	}
	free(map->ln);
	return (0);
}
