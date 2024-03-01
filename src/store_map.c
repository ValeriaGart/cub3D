#include "../incl/cub3d.h"

int	check_map_empty(t_map *map, int i)
{
	t_list	*lines_list;
	t_list	*tmp;

	lines_list = create_line_list(map);
	tmp = lines_list;
	map->size_list = ft_lstsize(lines_list);
	map->maps = ft_calloc((map->size_list + 1), sizeof(char *));
	if (!map->maps)
		return (ft_lstclear(&lines_list, free), 1);
	while (lines_list)
	{
		map->maps[i] = ft_strdup(lines_list->content);
		if (map->maps[i][ft_strlen(map->maps[i]) - 1] == '\n')
			map->maps[i][ft_strlen(map->maps[i]) - 1] = '\0';
		if (!map->maps[i])
		{
			ft_lstclear(&tmp, free);
			ft_putstr_fd("Error\nMalloc in map->maps failed\n", 2);
			return (1);
		}
		lines_list = lines_list->next;
		i++;
	}
	ft_lstclear(&tmp, free);
	return (0);
}

void	error_map_free(t_map *map, int *j)
{
	(*j)--;
	while (*j >= 0)
	{
		free(map->real_map[*j]);
		(*j)--;
	}
	free(map->real_map);
	map->real_map = NULL;
}

char	**store_real_map(t_map *map, int *i, int k)
{
	int	j;

	j = -1;
	while (*i < map->size_list)
	{
		map->real_map[++j] = ft_strdup(map->maps[*i]);
		if (!map->real_map[j])
		{
			error_map_free(map, &j);
			return (ft_error_msg("Error\nReal map cant be created\n"), NULL);
		}
		while (map->real_map[j][k] && map->real_map[j][k] != '\n'
			&& (map->real_map[j][k] == ' ' || map->real_map[j][k] == '\n'))
			k++;
		if (map->real_map[j][k] == '\0' || map->real_map[j][k] == '\n')
		{
			error_map_free(map, &j);
			return (ft_error_msg("Error\nMap is empty in store map\n"),
				NULL);
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
	while (map->maps && map->maps[++i])
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
			map->real_map = store_real_map(map, &i, 0);
			if (!map->real_map)
			{
				ft_putstr_fd("Error\nReal map cant be created in grm\n", 2);
				return (NULL);
			}
			i--;
		}
	}
	return (map->real_map);
}
