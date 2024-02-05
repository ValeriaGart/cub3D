#include "../incl/cub3d.h"

void	ft_map_set_zero(t_map **map)
{
	(*map)->NO = NULL;
	(*map)->SO = NULL;
	(*map)->WE = NULL;
	(*map)->EA = NULL;
	(*map)->up_colour =  NULL;
	(*map)->down_colour =  NULL;
	(*map)->map = NULL;
}

char	*ft_skip_empty_lines(fd)
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

char	*ft_direction_texture(int fd, t_map **map)
{
	(*map)->NO = ft_skip_empty_lines(fd);
	if (!(*map)->NO)
		return (ft_map_free(*map));
	(*map)->SO = ft_skip_empty_lines(fd);
	if (!(*map)->SO)
		return (ft_map_free(*map));
	(*map)->WE = ft_skip_empty_lines(fd);
	if (!(*map)->WE)
		return (ft_map_free(*map));
	(*map)->EA = ft_skip_empty_lines(fd);
	if (!(*map)->EA)
		return (ft_map_free(*map));
	(*map)->down_colour = ft_skip_empty_lines(fd);
	if (!(*map)->down_colour)
		return (ft_map_free(*map));
	(*map)->up_colour = ft_skip_empty_lines(fd);
	if (!(*map)->up_colour)
		return (ft_map_free(*map));
	return (NULL);
}

//TODO: count lines of map to know how much malloc. Store in t_data
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

t_map *ft_store_map(char **av, t_data *data)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_map_set_zero(&map);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(av[1]);
		return ((t_map *)ft_map_free);
	}
	ft_direction_texture(fd, &map);
	ft_twod_map(fd, &map, data);
	close(fd);
	if (!map)
	{
		get_next_line(-1, 1);
		return (ft_error_msg("Malloc failed\n"));
	}
	return (map);	
}
