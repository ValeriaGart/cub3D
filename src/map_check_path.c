#include "../incl/cub3d.h"

int	check_path_south(t_map *map)
{
	char	*line;
	int		i;
	int		k;

	line = ft_calloc(ft_strlen(map->sou), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->sou && ft_isspace(map->sou[i]))
		i++;
	while (map->sou[i])
	{
		line[++k] = map->sou[i];
		i++;
	}
	if (start_check_xpm(line))
		return (1);
	map->sou = line;
	return (0);
}

int	check_path_north(t_map *map)
{
	char	*line;
	int		i;
	int		k;

	line = ft_calloc(ft_strlen(map->nor), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->nor && ft_isspace(map->nor[i]))
		i++;
	while (map->nor[i])
	{
		line[++k] = map->nor[i];
		i++;
	}
	if (start_check_xpm(line))
		return (1);
	map->nor = line;
	return (0);
}

int	check_path_west(t_map *map)
{
	char	*line;
	int		i;
	int		k;

	line = ft_calloc(ft_strlen(map->wes), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->wes && ft_isspace(map->wes[i]))
		i++;
	while (map->wes[i])
	{
		line[++k] = map->wes[i];
		i++;
	}
	if (start_check_xpm(line))
		return (1);
	map->wes = line;
	return (0);
}

int	check_path_east(t_map *map)
{
	char	*line;
	int		i;
	int		k;

	line = ft_calloc(ft_strlen(map->eas), 1);
	if (!line)
		return (1);
	i = 2;
	k = -1;
	while (map->eas && ft_isspace(map->eas[i]))
		i++;
	while (map->eas[i])
	{
		line[++k] = map->eas[i];
		i++;
	}
	if (start_check_xpm(line))
		return (1);
	map->eas = line;
	return (0);
}
