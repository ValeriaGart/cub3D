#include "../incl/cub3d.h"

int main(int ac, char **av)
{
	t_data data;

	ft_set_data(&data);
//	data.map = malloc(sizeof(t_map));
//	if (!data.map)
//		return (ft_error_msg("Error\nMalloc in t_map failed\n"));
//	init_map(data.map);
	if (ft_map_check(ac, av, &data))
		return (1);
	ft_set_data(&data);
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
