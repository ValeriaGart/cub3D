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
	if (keysym == XK_e)
	{
		if (data->smallw_enabled == true)
			data->smallw_enabled = false;
		else
			data->smallw_enabled = true;
		ft_main_act(data);
	}
	if (keysym == XK_s || keysym == XK_Down)
		ft_direction_button('d', data, &(data->raycast));
	if (keysym == XK_w || keysym == XK_Up)
		ft_direction_button('u', data, &(data->raycast));
	if (keysym == XK_a || keysym == XK_Left)
		ft_direction_button('l', data, &(data->raycast));
	if (keysym == XK_d || keysym == XK_Right)
		ft_direction_button('r', data, &(data->raycast));
	return (0);
}
