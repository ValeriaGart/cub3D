#include "../incl/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n"), 1);
	ft_set_data(&data);
	if (ft_map_check(av, &data) || ft_square_map(data.map->real_map, data.map,
			&data))
	{
		ft_map_free(data.map);
		return (1);
	}
	ft_set_plr(data.map, &data);
	if (ft_open_window(&data) || ft_store_imgs(&data))
		return (ft_free_all(&data));
	printf("The game is running! 🤩\n");
	ft_init_raycast(&data);
	ft_main_act(&data);
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
