#include "../incl/cub3d.h"

int handle_x(t_data *data)
{
	ft_map_free(data->map);
	ft_free_window(data);
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_x(data);
	return (0);
}
