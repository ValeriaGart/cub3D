/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:39:56 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/21 17:44:32 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	assign_tex_if_unique(char **direction, t_map *map, int i)
{
	if (*direction != NULL)
	{
		ft_putstr_fd("Error\nDuplicate texture path\n", 2);
		return (1);
	}
	*direction = ft_strdup(map->maps[i]);
	if (!*direction)
		return (ft_error_msg("Error\nMalloc failed\n"), 1);
	return (0);
}

int	ft_some_weird_chars(t_map *map, int *i, int *j)
{
	if (map->maps[*i][*j] != 'S' && map->maps[*i][*j] != 'N'
		&& map->maps[*i][*j] != 'W' && map->maps[*i][*j] != 'E'
		&& map->maps[*i][*j] != 'F' && map->maps[*i][*j] != 'C'
		&& map->maps[*i][*j] != '1' && !ft_isspace(map->maps[*i][*j]))
	{
		ft_error_msg("Some weird chars in map\n");
		return (1);
	}
	return (0);
}

int	check_direction_name(t_map *map, int *i, int *j)
{
	int	success;

	success = -1;
	if ((map->maps[*i][*j] == 'S' && map->maps[*i][(*j)
		+ 1] == 'O' && map->maps[*i][(*j) + 2] == ' '))
		success = assign_tex_if_unique(&(map->sou), map, *i);
	else if ((map->maps[*i][*j] == 'N' && map->maps[*i][(*j)
		+ 1] == 'O' && map->maps[*i][(*j) + 2] == ' '))
		success = assign_tex_if_unique(&(map->nor), map, *i);
	else if ((map->maps[*i][*j] == 'W' && map->maps[*i][(*j)
		+ 1] == 'E' && map->maps[*i][(*j) + 2] == ' '))
		success = assign_tex_if_unique(&(map->wes), map, *i);
	else if ((map->maps[*i][*j] == 'E' && map->maps[*i][(*j)
		+ 1] == 'A' && map->maps[*i][(*j) + 2] == ' '))
		success = assign_tex_if_unique(&(map->eas), map, *i);
	if (success == 1)
		return (1);
	return (0);
}

int	check_inforhead(t_map *map, int i, int j)
{
	while (i <= map->size_list - 1 && map->maps[i] != NULL)
	{
		if (map->maps[i][0] == '\n')
		{
			i++;
			continue ;
		}
		j = 0;
		while (map->maps[i][j] && ft_isspace(map->maps[i][j]))
			j++;
		if (map->maps[i][j] && ft_some_weird_chars(map, &i, &j))
			return (1);
		if (check_colour(map, &i, &j))
			return (1);
		if (check_direction_name(map, &i, &j))
			return (1);
		i++;
	}
	if (map->nor == NULL || map->sou == NULL || map->wes == NULL
		|| map->eas == NULL || map->ceil == NULL || map->floor == NULL)
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
