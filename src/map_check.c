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

int	check_empty_map(char **av)
{
	int		fd;
	char 	*line;
	int 	i;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nMap file not found\n", 2);
		return (1);
	}
	i = 0;
	line = NULL;
	while (get_next_line(fd, line[i]) != NULL)
	{
		if (line[0] != '\0')
			return (0);
		free(line);
	}
	if (*line == 0)
	{
		ft_putstr_fd("Error\nMap file is empty\n", 2);
		return (1);
	}
	return (0);
}

int	check_map_name(char **av)
{
	int i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if (!ft_strcmp(av[1] + i, ".cub"))
			return (1);
		i++;
	}
	return (0);
}

// int	check_colour(t_map *map, char *line)
// {
// 	int		red;
// 	int		green;
// 	int		blue;

// 	if (line[0] == ',')
// 		return (1);
// 	red = ft_atoi(line + 2);
//     return (red << 16 | green << 8 | blue);
// }

int	ft_set_colour(t_map *map, char *line)
{
	if (line[0] == 'C')
	{
		map->up_colour = ft_strdup(line + 1);
		// map->ceil_colour = check_colour(map, map->ceil_colour);
	}
	else if (line[0] == 'F')
	{
		map->down_colour = ft_strdup(line + 1);
		// map->floor_colour = check_colour(map, map->floor_colour);
	}
	// if (map->up_colour == 1 || map->down_colour == 1)
	// {
	// 	ft_putstr_fd("Error\nColour is default\n", 2);
	// 	return (1);
	// }
	else
		return (1);
	return (0);
}

//C for color, F for floor, SO for south, NO for north, WE for west, EA for east
int	check_inforead(char **av, t_map *map)
{
	int		fd;
	char 	*line;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break;
		else if (line[0] == 'C' || line[0] == 'F')
			ft_set_colour(map, line);
		else if (map->SO == NULL && (line[0] == 'S' && line[1] == 'O'))
			map->SO = ft_strdup(line + 2);
		else if (map->NO == NULL && (line[0] == 'N' && line[1] == 'O'))
			map->NO = ft_strdup(line + 2);
		else if (map->WE == NULL && (line[0] == 'W' && line[1] == 'E'))
			map->WE = ft_strdup(line + 2);
		else if (map->EA == NULL && (line[0] == 'E' && line[1] == 'A'))
			map->EA = ft_strdup(line + 2);
	}
	close(fd);
	ft_putstr_fd("Error\nNo map info found\n", 2);
	return (1);
}

//check before "./" is space or not, and after space must include "." and "/" together no space, then check path afterwards
int	check_symbols_path(char *line, int i)
{
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		if (line[i] == '.' && line[i + 1] == '/')
		{
			i += 2;
			if (ft_isspace(line[i]))
				return (1);
			while (line[i] != '\0')
			{
				if (line[i] == '.' && !ft_strcmp(line + i, ".xpm"))
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

//check path after the directions
int	check_path_SO(t_map *map)
{
	char 	*line;
	int 	i;
	int		k;

	line = ft_calloc(ft_strlen(map->SO), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->SO && ft_isspace(map->SO[i]))
		i++;
	while(map->SO && !ft_isspace(map->SO[i]))
	{
		line[++k] = map->SO[i];
		i++;
	}
	free(map->SO);
	map->SO = line;
	if (check_symbols_path(map->SO, 0))
		return (1);
	return (0);
}

int	ft_map_check(int ac, char **av, t_data *data)
{
	if (check_ac(ac, data) && check_empty_map(av))
		return (1);
	else if (check_map_name(av) && check_inforead(av, data->map))
		return (1);
	else if (check_path_SO(data->map))
		return (1);
	return (0);
}
