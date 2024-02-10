#include "../incl/cub3d.h"

// void	ft_map_set_zero(t_map **map)
// {
// 	(*map)->nor = NULL;
// 	(*map)->sou = NULL;
// 	(*map)->wes = NULL;
// 	(*map)->eas = NULL;
// 	(*map)->ceil =  NULL;
// 	(*map)->floor =  NULL;
// 	(*map)->map = NULL;
// }

char	*ft_skip_empty_lines(int fd)
{
	char	*ret;

	ret = get_next_line(fd, 0);
	if (!ret)
		return (NULL);
	while (ft_isspace(ret[0]) || ret[0] == '\n')
	{
		free(ret);
		ret = get_next_line(fd, 0);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

/*char	*ft_direction_texture(int fd, t_map **map)
{
	(*map)->nor = ft_skip_empty_lines(fd);
	if (!(*map)->nor)
		return (ft_map_free(*map));
	(*map)->sou = ft_skip_empty_lines(fd);
	if (!(*map)->sou)
		return (ft_map_free(*map));
	(*map)->wes = ft_skip_empty_lines(fd);
	if (!(*map)->wes)
		return (ft_map_free(*map));
	(*map)->eas = ft_skip_empty_lines(fd);
	if (!(*map)->eas)
		return (ft_map_free(*map));
	(*map)->F = ft_skip_empty_lines(fd);
	if (!(*map)->F)
		return (ft_map_free(*map));
	(*map)->C = ft_skip_empty_lines(fd);
	if (!(*map)->C)
		return (ft_map_free(*map));
	return (NULL);
}*/

void	*ft_twod_map(int fd, t_map **map, t_data *data)
{
	int	i;

	i = 0;
	if (!*map)
		return (NULL);
	(*map)->map = ft_calloc(sizeof(char *), (data->line_num + 1));
	if (!(*map)->map)
		return (ft_map_free(*map));
	while (i < data->line_num)
	{
		if (i == 0)
			(*map)->map[i] = ft_skip_empty_lines(fd);
		else
			(*map)->map[i] = get_next_line(fd, 0);
		if (!(*map)->map[i])
		{
			while (i >= 0)
				free((*map)->map[--i]);
			free((*map)->map);
			(*map)->map = NULL;
			return (ft_map_free(*map));
		}
		i++;
	}
	return (NULL);
}

// TODO: I ald checked the fd in ft_check_map.c, do you still think you need it? 
//TODO: and I ald checked for empty space for infor map, would you still wanna save the map again, since I ald did
//todo: cuz I think I ald read the map in check_inforhead function in map_check_info.c
// t_map *ft_store_map(char **av, t_data *data)
// {
// 	t_map	*map;
// 	int		fd;

// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		return (NULL);
// 	ft_map_set_zero(&map);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		perror(av[1]);
// 		return ((t_map *)ft_map_free);
// 	}
// 	ft_direction_texture(fd, &map);
// 	ft_twod_map(fd, &map, data);
// 	close(fd);
// 	if (!map)
// 	{
// 		get_next_line(-1, 1);
// 		return (ft_error_msg("Malloc failed\n"));
// 	}
// 	return (map);	
// }
