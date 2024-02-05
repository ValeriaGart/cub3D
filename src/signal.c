#include "../incl/cub3d.h"

// TODO: free here before exit
int handle_x(t_data *data)
{
	ft_map_free(data->map);
	ft_free_window(data);
	exit(0);
}
