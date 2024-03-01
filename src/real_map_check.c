#include "../incl/cub3d.h"

int	first_last_line(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->real_map[++i])
	{
		if (i == 0 || i == map->y_map - 1)
		{
			j = -1;
			while (map->real_map[i][++j] && map->real_map[i][j] != '\n')
			{
				if (map->real_map[i][j] != '1' && map->real_map[i][j] != ' ')
				{
					ft_putstr_fd("Error\nMap is not closed for first and last line\n",
						2);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_double_char(t_map *map, int i, int count)
{
	int	j;

	while (map->real_map[++i])
	{
		j = -1;
		while (map->real_map[i][++j])
		{
			if (map->real_map[i][j] == 'N' || map->real_map[i][j] == 'S'
				|| map->real_map[i][j] == 'W' || map->real_map[i][j] == 'E')
			{
				count++;
				if (map->real_map[i][j + 1] == 'N' || map->real_map[i][j
					+ 1] == 'S' || map->real_map[i][j + 1] == 'W'
					|| map->real_map[i][j + 1] == 'E')
					count++;
				if (count > 1)
				{
					ft_putstr_fd("Error\nMap contains invalid characters\n", 2);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_map_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->real_map[++i])
	{
		j = -1;
		while (map->real_map[i][++j])
		{
			if ((map->real_map[i][j] != '0' && map->real_map[i][j] != '1'
					&& map->real_map[i][j] != ' ')
				&& (map->real_map[i][j] != 'N' && map->real_map[i][j] != 'S'
					&& map->real_map[i][j] != 'W'
					&& map->real_map[i][j] != 'E'))
			{
				ft_putstr_fd("Error\nMap contains invalid characters\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

int	check_zero(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->real_map[++i] != NULL)
	{
		j = -1;
		while (map->real_map[i][++j])
		{
			if (map->real_map[i][j] == '0')
			{
				if (when_is_wrong(map, i, j))
					return (1);
				else if (ft_strncmp(map->real_map[i], map->real_map[i - 1],
						map->real_map[i][j]) == 0
					|| ft_strncmp(map->real_map[i], map->real_map[i + 1],
						map->real_map[i][j]) == 0)
				{
					ft_putstr_fd("Error\nMap is not closed for 0\n", 2);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map->real_map[++i])
	{
		j = -1;
		while (map->real_map[i][++j])
		{
			if (ft_strchr("NSWE", map->real_map[i][j]))
			{
				count++;
				if (when_is_wrong(map, i, j))
					return (1);
			}
		}
	}
	if (count != 1)
	{
		ft_putstr_fd("Error\nMap doesnt contain right player\n", 2);
		return (1);
	}
	return (0);
}
