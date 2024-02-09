#include "../incl/cub3d.h"

//check before "./" is space or not, and after space must include "." and "/" together no space, then check path afterwards
int	check_content_path(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '.' && !ft_strcmp(line + i, ".xpm"))
		{
			ft_putstr_fd("Error\nPath is not valid\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

//check path after the directions
int	check_path_SO(t_map *map)
{
	char 	*line;
	int 	i;
	int		k;

	line = ft_calloc(ft_strlen(map->SO), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->SO && ft_isspace(map->SO[i]))
		i++;
	while(map->SO && !ft_isspace(map->SO[i]))
	{
		line[++k] = map->SO[i];
		i++;
	}
	if (!ft_strcmp(line, ".xpm"))
	{
		ft_putstr_fd("Error\nPath is not valid\n", 2);
		free(map->SO);
		return (1);
	}
	free(map->SO);
	map->SO = line;
	return (0);
}
