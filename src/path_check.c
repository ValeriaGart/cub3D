#include "../incl/cub3d.h"

int	start_check_xpm(char *line)
{
	int	k;

	if (ft_strlen(line) <= 4)
		return (ft_error_msg("Map info is not a full \".xpm\"\n"), 1);
	k = 0;
	while (line[k] != '\0')
		k++;
	while(k && ft_strchr(".xpm", line[k]))
		k--;
	k++;
	if (!line || !ft_strnstr(line + k, ".xpm", 4))
		return (ft_error_msg("Map info is not a \".xpm\"  file\n"), 1);
	k += 4;
	while (line && line[k] != '\0')
	{
		if (!ft_isspace(line[k++]))
			return (ft_error_msg("Map info has more than 1 \".xpm\"\n"),
				1);
	}
	return (0);
}

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
	{
		free(line);
		return (1);
	}
	free(map->sou);
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
		return (free(line), 1);
	free(map->nor);
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
	{
		free(line);
		return (1);
	}
	free(map->wes);
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
	{
		free(line);
		return (1);
	}
	free(map->eas);
	map->eas = line;
	return (0);
}
