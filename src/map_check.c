#include "../incl/cub3d.h"

int	check_ac(int ac, t_data *data)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong arguments 😰\n", 2);
		return (1);
	}
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("Error\nMalloc in t_map failed\n", 2);
		return (1);
	}
	init_map(data->map);
	return (0);
}

int	check_map_name(char **av)
{
	int	i;

	i = 0;
	if (ft_strlen(av[1]) <= 4)
	{
		ft_putstr_fd("Error\nMap file is not a \".cub\" file\n", 2);
		return (1);
	}
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (!av[1][i] || !ft_strnstr(av[1] + i, ".cub", 4))
	{
		ft_putstr_fd("Error\nMap file is not a \".cub\" file\n", 2);
		return (1);
	}
	if (av[1][i + 4] != '\0')
	{
		ft_putstr_fd("Error\nMap file is not a \".cub\" file\n", 2);
		return (1);
	}
	return (0);
}

int	check_map_empty(t_map *map, int i)
{
	t_list	*lines_list;
	t_list	*tmp;

	lines_list = create_line_list(map);
	tmp = lines_list;
	map->size_list = ft_lstsize(lines_list);
	map->maps = ft_calloc((map->size_list + 1), sizeof(char *));
	if (!map->maps)
		return (ft_lstclear(&lines_list, free), 1);
	while (lines_list)
	{
		map->maps[i] = ft_strdup(lines_list->content);
		if (map->maps[i][ft_strlen(map->maps[i]) - 1] == '\n')
			map->maps[i][ft_strlen(map->maps[i]) - 1] = '\0';
		if (!map->maps[i])
		{
			ft_lstclear(&tmp, free);
			ft_putstr_fd("Error\nMalloc in map->maps failed\n", 2);
			return (1);
		}
		lines_list = lines_list->next;
		i++;
	}
	ft_lstclear(&tmp, free);
	return (0);
}

int	ft_map_check(int ac, char **av, t_data *data)
{
	if (check_ac(ac, data) || check_map_name(av))
		return (1);
	data->map->fd = open(av[1], O_RDONLY);
	if (data->map->fd < 0)
	{
		ft_putstr_fd("Error\nMap file not found\n", 2);
		close(data->map->fd);
		return (1);
	}
	else if (check_map_empty(data->map, 0))
	{
		close(data->map->fd);
		return (1);
	}
	close(data->map->fd);
	if (check_inforhead(data->map, 0, 0))
		return (1);
	else if (check_four_paths(data->map))
		return (1);
	if (get_real_map(data->map) == NULL)
		return (1);
	return (0);
}
