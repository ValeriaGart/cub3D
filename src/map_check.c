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
	//TODO: valeria delete next 2 lines
	while (av[1][i] && av[1][i] == '.')
		i++;
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
	else if (get_real_map(data->map) == NULL || check_real_map(data->map))
		return (1);
	return (0);
}
