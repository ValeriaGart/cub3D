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

char	**store_real_map(t_map *map, int *i)
{
	int	j;

	j = -1;
	while (*i < map->size_list)
	{
		map->real_map[++j] = ft_strdup(map->maps[*i]);
		if (!map->real_map[j])
		{
			j--;
			while (j >= 0)
			{
				free(map->real_map[j]);
				j--;
			}
			free(map->real_map);
			map->real_map = NULL;
			ft_putstr_fd("Error\nReal map cant be created\n", 2);
			return (NULL);
		}
		if ((int)ft_strlen(map->real_map[j]) > map->x_map)
			map->x_map = (int)ft_strlen(map->real_map[j]);
		(*i)++;
	}
	return (map->real_map);
}

char	**get_real_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->maps[++i])
	{
		j = 0;
		while (map->maps[i][j] && ft_isspace(map->maps[i][j]))
			j++;
		if (map->maps[i][j] == '1')
		{
			map->y_map = map->size_list - i;
			map->real_map = ft_calloc(sizeof(char *), (map->y_map + 1));
			if (!map->real_map)
				return (NULL);
			map->real_map = store_real_map(map, &i);
		}
	}
	return (map->real_map);
}
