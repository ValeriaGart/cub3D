#include "../incl/cub3d.h"

t_list	*create_line_list(t_map *map)
{
	char	*tmp;
	t_list	*lines_list;
	t_list	*new_node;

	lines_list = NULL;
	tmp = get_next_line(map->fd);
	while (tmp)
	{
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&lines_list, free);
			ft_putstr_fd("Error\nList cant be created\n", 2);
			return (NULL);
		}
		ft_lstadd_back(&lines_list, new_node);
		tmp = get_next_line(map->fd);
	}
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
