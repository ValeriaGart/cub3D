#include "../incl/cub3d.h"

void	ft_storre_map(char *str, t_data *data)
{
	char	*new;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	new = get_next_line(fd, 0);
	data->map = malloc(sizeof(t_map));
	data->map->map = ft_calloc(sizeof(char *), 11);
	while (new)
	{
		printf("%s", new);
		data->map->map[i] = new;
		new = get_next_line(fd, 0);
		i++;
	}
	printf("\n");
	data->map->x_map = 20;
	data->map->y_map = 10;
}

int main(int ac, char **av)
{
	t_data data;

	(void)av;
	(void)ac;
	ft_set_data(&data);
	//if (ft_map_check(ac, av, &data))
	//	return (1);
	ft_storre_map(av[1], &data);
	ft_set_plr(data.map, &data);
	printf("The game is running! 🤩\n");
	if (ft_open_window(&data))
		return (1);
	if (ft_main_act(&data))
		return (ft_free_all(&data));
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
