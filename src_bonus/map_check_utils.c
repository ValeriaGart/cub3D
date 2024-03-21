/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:39:59 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/21 17:44:35 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

t_list	*create_line_list(t_map *map)
{
	char	*tmp;
	t_list	*lines_list;
	t_list	*new_node;

	lines_list = NULL;
	tmp = get_next_line(map->fd, 0);
	while (tmp && *tmp)
	{
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&lines_list, free);
			get_next_line(map->fd, 1);
			return (ft_error_msg("List cant be created\n"));
		}
		ft_lstadd_back(&lines_list, new_node);
		tmp = get_next_line(map->fd, 0);
	}
	get_next_line(map->fd, 1);
	if (!tmp)
		return (ft_lstclear(&lines_list, free),
			ft_error_msg("Get_next_line failed\n"));
	return (lines_list);
}

int	ft_isascii_no_space(int c)
{
	if (ft_isspace(c))
		return (0);
	else
		return (1);
}

int	when_is_wrong(t_map *map, int i, int j)
{
	if (!ft_strchr("01NSWE", map->real_map[i][j + 1]) || !ft_strchr("01NSWE",
			map->real_map[i][j - 1]) || !ft_strchr("01NSWE", map->real_map[i
			+ 1][j]) || !ft_strchr("01NSWE", map->real_map[i - 1][j]))
	{
		ft_putstr_fd("Error\nMap is not closed, realated to general chars\n",
			2);
		return (1);
	}
	else if (map->real_map[i][j + 1] == '\0' || map->real_map[i][j - 1] == '\0'
		|| map->real_map[i + 1][j] == '\0' || map->real_map[i - 1][j] == '\0')
	{
		ft_putstr_fd("Error\nMap is not closed, related to NULL\n", 2);
		return (1);
	}
	else if (map->real_map[i][j + 1] == '\n' || map->real_map[i][j - 1] == '\n'
		|| map->real_map[i + 1][j] == '\n' || map->real_map[i - 1][j] == '\n')
	{
		ft_putstr_fd("Error\nMap is not closed, related to newline\n", 2);
		return (1);
	}
	return (0);
}
