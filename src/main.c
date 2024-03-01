#include "../incl/cub3d.h"

int main(int ac, char **av)
{
	t_data data;

	ft_set_data(&data);
	if (ft_map_check(ac, av, &data))
	{
		ft_map_free(data.map);
		return (1);
	}
	ft_set_plr(data.map, &data);
	printf("The game is running! 🤩\n");
	if (ft_open_window(&data))
		return (1);
	ft_init_raycast(&data);
	mlx_loop_hook(data.mlx_ptr, &ft_main_act, &data);
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

