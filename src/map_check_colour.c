/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:39:52 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/21 17:39:53 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	more_than_3digits(char *line, int *i, int *arg)
{
	while (line[*i] && line[*i] != '\n' && *arg == 3)
	{
		if (line[*i] == ',')
			return (1);
		else if (ft_isascii_no_space(line[*i]))
		{
			ft_putstr_fd("Error\nMore than 3 didgits \n", 2);
			return (1);
		}
		else
			(*i)++;
	}
	return (0);
}

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
	if (more_than_3digits(line, i, arg))
	{
		free(which_colour);
		return (NULL);
	}
	(*i)++;
	return (which_colour);
}

int	comma_colour(char *line, int i, int arg, int comma)
{
	int	red;
	int	green;
	int	blue;

	while (ft_isspace(line[i]))
	{
		if (line[i + 1] == ',')
			return (1);
		i++;
	}
	red = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	green = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
	blue = ft_atoi_from_malloc(set_colour(line, &i, &arg, &comma));
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
		if (assign_tex_if_unique(&map->ceil, map, *i))
			return (1);
		(*j)++;
		map->ceil_colour = comma_colour(&map->maps[*i][*j], 0, 0, 0);
	}
	else if (map->maps[*i][*j] == 'F')
	{
		if (assign_tex_if_unique(&map->floor, map, *i))
			return (1);
		(*j)++;
		map->floor_colour = comma_colour(&map->maps[*i][*j], 0, 0, 0);
	}
	if (map->ceil_colour == 1 || map->floor_colour == 1)
		return (1);
	return (0);
}
