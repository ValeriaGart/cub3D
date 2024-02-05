#include "../incl/cub3d.h"

int main(int ac, char **av)
{
	t_data data;
	t_mini_w	mini;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong arguments 😰\n", 2);
		return (1);
	}
	mini.py = 480 - 40;
	mini.px = 60;
	ft_set_data(&data);
	if (ft_map_check(av, &data))
		return (1);
	printf("The game is running! 🤩\n");
	if (ft_open_window(&data))
		return (1);
	data.mini = &mini;
	if (ft_main_act(&data))
		return (ft_free_all(&data));
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
//	mlx_loop_hook(data.win_ptr, &ft_main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
