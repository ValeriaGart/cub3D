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

int	check_only_spaces(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_empty_map(t_map *map, char **av)
{
	char	*line;
	int		i;

	map->fd = open(av[1], O_RDONLY);
	if (map->fd < 0)
	{
		ft_putstr_fd("Error\nMap file not found\n", 2);
		return (1);
	}
	i = 0;
	line = get_next_line(map->fd, 0);
	while (line != NULL)
	{
		if (line[0] != '\0' && line[0] != '\n')
			return (0);
		free(line);
		line = get_next_line(map->fd, 0);
	}
	if (check_only_spaces(line))
	{
		ft_putstr_fd("Error\nMap file is empty\n", 2);
		return (1);
	}
	ft_putstr_fd("Error\nMap file is empty\n", 2);
	return (1);
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

char	*set_colour(char *line, int *i, int *arg, int *comma)
{
	char	*which_colour;
	int		num_len;

	(*arg)++;
	while (ft_isspace(line[*i]))
		(*i)++;
	if (!ft_isdigit(line[*i]))
		return (NULL);
	num_len = *i;
	while (ft_isdigit(line[*i]))
		(*i)++;
	which_colour = ft_substr(line, num_len, *i - num_len);
	if (!which_colour)
		return (NULL);
	while (ft_isspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (line[*i] == ',')
		(*comma)++;
	while (line[*i] != '\n' && *arg == 3)
	{
		if (line[*i] != ',')
			return (NULL);
		(*i)++;
	}
	return (which_colour);
}

int	check_colour(char **line, int i, int arg)
{
	int		red;
	int		green;
	int		blue;
	int		comma;
	int		j;

	j = i;
	if (line[i][0] == ',')
		return (1);
	comma = 0;
	red = ft_atoi(set_colour(line[i], &i, &arg, &comma));
	i++;
	green = ft_atoi(set_colour(line[j], &i, &arg, &comma));
	i++;
	blue = ft_atoi(set_colour(line[j], &i, &arg, &comma));
	if ((red == -1 || green == -1 || blue == -1) || (red < 0
			|| red > 255) || (green < 0 || green > 255)
		|| (blue < 0 || blue > 255) || comma != 2 || arg != 3)
	{
		ft_putstr_fd("Error\nColour's number is not valid \n", 2);
		return (1);
	}
	return (red << 16 | green << 8 | blue);
}

int	ft_set_colour(t_map *map, char *line)
{
	if (line[0] == 'C')
	{
		map->up_colour = ft_strdup(line + 1);
		line++;
		map->ceil_colour = check_colour(&line, 0, 0);
	}
	else if (line[0] == 'F')
	{
		map->down_colour = ft_strdup(line + 1);
		line++;
		map->floor_colour = check_colour(&line, 0, 0);
	}
	if (map->ceil_colour == 1 || map->floor_colour == 1)
		return (1);
	return (0);
}

//C for color, F for floor, SO for south, NO for north, WE for west, EA for east
int	check_inforead(char **av, t_map *map)
{
	map->fd = open(av[1], O_RDONLY);
	while (1)
	{
		map->ln = get_next_line(map->fd, 0);
		if (map->ln == NULL)
			break;
		else if (ft_set_colour(map, map->ln))
			return (1);
		else if (map->SO == NULL && (map->ln[0] == 'S' && map->ln[1] == 'O'))
			map->SO = ft_strdup(map->ln + 2);
		else if (map->NO == NULL && (map->ln[0] == 'N' && map->ln[1] == 'O'))
			map->NO = ft_strdup(map->ln + 2);
		else if (map->WE == NULL && (map->ln[0] == 'W' && map->ln[1] == 'E'))
			map->WE = ft_strdup(map->ln + 2);
		else if (map->EA == NULL && (map->ln[0] == 'E' && map->ln[1] == 'A'))
			map->EA = ft_strdup(map->ln + 2);
	}
	if (map->NO == NULL || map->SO == NULL || map->WE == NULL || map->EA == NULL)
	{
		ft_putstr_fd("Error\nMissing texture path\n", 2);
		return (1);
	}
	free(map->ln);
	return (0);
}

int	ft_map_check(int ac, char **av, t_data *data)
{
	if (check_ac(ac, data) || check_map_name(av))
		return (1);
	else if (check_empty_map(data->map, av) || check_inforead(av, data->map))
		return (1);
	else if (check_path_SO(data->map))
		return (1);
	close(data->map->fd);
	return (0);
}
