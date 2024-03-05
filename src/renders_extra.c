#include "../incl/cub3d.h"

void	ft_fill_spaces(char **map, int i, t_map *maps)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (ft_isspace(map[i][j]))
			map[i][j] = '1';
		j++;
	}
	while (j < maps->x_map)
	{
		map[i][j] = '1';
		j++;
	}
}

int	ft_square_map(char **map, t_map *maps, t_data *data)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (map[i])
	{
		new = map[i];
		map[i] = ft_calloc(sizeof(char), maps->x_map + 1);
		if (!map[i])
			return (1);
		ft_strlcpy(map[i], new, ft_strlen(new));
		free(new);
		ft_fill_spaces(map, i, maps);
		i++;
	}
	data->map->real_map = map;
	return (0);
}

void	ft_put_pixel_raycast(t_data *data, int colour, int z)
{
	int	offset;

	offset = z * 4;
	*((unsigned int *)(offset + (&(data->img))->addr)) = colour;
}

/*void	ft_drawtheline(int x, int y, t_data *data, int colour)
{
	while (x < y)
	{
		ft_put_pixel_raycast(data, colour, x);
		x += WIDTH_X;
	}
}*/

double	get_step(t_rc *rc)
{
	double	wall;

	if (!rc->side)
		wall = rc->posY + rc->perpWallDist * rc->rayDirY;
	else
		wall = rc->posX + rc->perpWallDist * rc->rayDirX;
	rc->tex = (int)((double)(wall - floor(wall)) * (double)64);
	if ((!rc->side && rc->rayDirX < 0)
		|| (rc->side && rc->rayDirY > 0))
		rc->tex = 64 - rc->tex - 1;
	return (1.0 * (double)64 / (double)rc->lineheight);
}

//embrace the chaos version
/*void	ft_draw_pic(int x, int y, t_data *data, int colour, int real_x)
{
	double	step;
	double	tex_p;

	(void)real_x;
	step = get_step(&data->raycast);
	tex_p = (x - HEIGHT_Y / 2 + data->raycast.lineheight / 2) * step;
	while (x <= y)
	{
		data->raycast.tex_y = (int)tex_p & 63;
		tex_p += step;
		colour = *(int *)(data->map->nor(comment.addr)
				+ (data->raycast.tex_y * data->no.line_size
					+ data->raycast.tex * (data->no.bits_per_pixel / 8)));
		ft_put_pixel_raycast(data, colour, x);
		x += WIDTH_X;
	}
}*/

void	ft_draw_pic(int x, int y, t_data *data, int colour, int real_x)
{
	double	step;
	double	tex_p;

	step = get_step(&data->raycast);
	tex_p = (((x - real_x) / WIDTH_X) - HEIGHT_Y / 2 + data->raycast.lineheight / 2) * step;
	while (x <= y)
	{
		data->raycast.tex_y = (int)tex_p & 63;
		tex_p += step;
		colour = *(int *)(data->no.addr
				+ (data->raycast.tex_y * data->no.line_size
					+ data->raycast.tex * (data->no.bits_per_pixel / 8)));
		ft_put_pixel_raycast(data, colour, x);
		x += WIDTH_X;
	}
}
