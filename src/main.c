#include "../incl/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong arguments 😰\n" , 2);
		return (1);
	}
	if (ft_map_check(av))
		return (1);
	printf("The game is running! 🤩\n");
	if (ft_open_window(&data))
		return (1);
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
