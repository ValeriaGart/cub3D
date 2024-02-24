#include "../incl/cub3d.h"

char	*set_colour(char *line, int *i, int *arg, int *comma)
{
	char	*which_colour;
	int		num_len;

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
	(*arg)++;
	if (line[*i] == ',')
		(*comma)++;
	while (line[*i] && line[*i] != '\n' && *arg == 3)
	{
		if (line[*i] == ',')
			return (NULL);
		else if (ft_isascii_no_space(line[*i]))
		{
			ft_putstr_fd("Error\nToo many digits \n", 2);
			return (NULL);
		}
		else
			(*i)++;
	}
	return (which_colour);
}

int	comma_colour(char *line, int i, int arg, int comma)
{
	int	red;
	int	green;
	int	blue;
	int	temp;

	while (ft_isspace(line[i]))
	{
		if (line[i + 1] == ',')
			return (1);
		i++;
	}
	red = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	i++;
	green = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	i++;
	blue = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	i++;
	temp = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0
			|| blue > 255) || comma != 2 || arg != 3)
	{
		ft_putstr_fd("Error\nColour's number is not valid \n", 2);
		return (1);
	}
	return (red << 16 | green << 8 | blue);
}

int	check_colour(t_map *map, int *i, int *j)
{
	if (map->maps[*i][*j] == 'C')
	{
		map->ceil = ft_strdup(map->maps[*i] + 1);
		if (!map->ceil)
			return (1);
		(*j)++;
		map->ceil_colour = comma_colour(&map->maps[*i][*j], 0, 0, 0);
	}
	else if (map->maps[*i][*j] == 'F')
	{
		map->floor = ft_strdup(map->maps[*i] + 1);
		if (!map->floor)
			return (1);
		(*j)++;
		map->floor_colour = comma_colour(&map->maps[*i][*j], 0, 0, 0);
	}
	if (map->ceil_colour == 1 || map->floor_colour == 1)
		return (1);
	return (0);
}
