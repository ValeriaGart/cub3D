#include "../incl/cub3d.h"

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

int	comma_colour(char **line, int i, int arg)
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

int	check_colour(t_map *map)
{
	if (map->ln[0] == 'C')
	{
		map->ceil = ft_strdup(map->ln + 1);
		map->ln++;
		map->ceil_colour = comma_colour(&map->ln, 0, 0);
	}
	else if (map->ln[0] == 'F')
	{
		map->floor = ft_strdup(map->ln + 1);
		map->ln++;
		map->floor_colour = comma_colour(&map->ln, 0, 0);
	}
	if (map->ceil_colour == 1 || map->floor_colour == 1)
		return (1);
	return (0);
}
