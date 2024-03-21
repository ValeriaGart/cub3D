/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:40:09 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/21 17:44:45 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	start_check_xpm(char *line)
{
	int	k;

	if (ft_strlen(line) <= 4)
		return (ft_error_msg("Map info is not a full \".xpm\"\n"), 1);
	k = 0;
	while (line[k] != '\0')
		k++;
	while (k && line[k] != '.')
		k--;
	if (!line || !ft_strnstr(line + k, ".xpm", 4))
		return (ft_error_msg("Map info is not a \".xpm\"  file\n"), 1);
	if (line[k + 4] != '\0')
		return (ft_error_msg("Map info has sth after \".xpm\"\n"), 1);
	return (0);
}

int	check_path_south(t_map *map)
{
	int	i;
	int	k;

	i = 2;
	k = -1;
	while (map->sou && (ft_isspace(map->sou[i]) && map->sou[i] != '\n'))
		i++;
	while (map->sou[i])
	{
		map->sou[++k] = map->sou[i];
		i++;
	}
	map->sou[++k] = '\0';
	if (start_check_xpm(map->sou))
		return (1);
	return (0);
}

int	check_path_north(t_map *map)
{
	int	i;
	int	k;

	i = 2;
	k = -1;
	while (map->nor && (ft_isspace(map->nor[i]) && map->nor[i] != '\n'))
		i++;
	while (map->nor[i])
	{
		map->nor[++k] = map->nor[i];
		i++;
	}
	map->nor[++k] = '\0';
	if (start_check_xpm(map->nor))
		return (1);
	return (0);
}

int	check_path_west(t_map *map)
{
	int	i;
	int	k;

	i = 2;
	k = -1;
	while (map->wes && (ft_isspace(map->wes[i]) && map->wes[i] != '\n'))
		i++;
	while (map->wes[i])
	{
		map->wes[++k] = map->wes[i];
		i++;
	}
	map->wes[++k] = '\0';
	if (start_check_xpm(map->wes))
		return (1);
	return (0);
}

int	check_path_east(t_map *map)
{
	int	i;
	int	k;

	i = 2;
	k = -1;
	while (map->eas && (ft_isspace(map->eas[i]) && map->eas[i] != '\n'))
		i++;
	while (map->eas[i])
	{
		map->eas[++k] = map->eas[i];
		i++;
	}
	map->eas[++k] = '\0';
	if (start_check_xpm(map->eas))
		return (1);
	return (0);
}
