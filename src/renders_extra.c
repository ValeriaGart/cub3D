#include "../incl/cub3d.h"

void	ft_put_pixel_raycast(t_data *data, int x, int y, int colour, int z)
{
	int offset;

	if (z)
		offset = z * 4;
	else
		offset = ((y * WIDTH_X) + x) * 4;
	*((unsigned int *)(offset + (&(data->img))->addr)) = colour;
}

void	ft_drawtheline(int x, int y, t_data *data, int colour)
{
	while (x < y)
	{
		ft_put_pixel_raycast(data, 0, 0, colour, x);
		x += WIDTH_X;
	}
}
