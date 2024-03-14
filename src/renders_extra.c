#include "../incl/cub3d.h"

int	ft_square_map(char **map, t_map *maps, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
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

double	get_step(t_rc *rc)
{
	double	wall;

	if (!rc->side)
		wall = rc->pos_y + rc->perpwalldist * rc->ray_dir_y;
	else
		wall = rc->pos_x + rc->perpwalldist * rc->ray_dir_x;
	rc->tex = (int)((double)(wall - floor(wall))*(double)64);
	if ((!rc->side && rc->ray_dir_x < 0)
		|| (rc->side && rc->ray_dir_y > 0))
		rc->tex = 64 - rc->tex - 1;
	return (1.0 * (double)64 / (double)rc->lineheight);
}

//embrace the chaos version
/*void	ft_draw_pic(int x, int y, t_data *data, int real_x)
{
	double	step;
	double	tex_p;
	int	colour;

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

void	ft_draw_pic(int x, int y, t_data *data, int real_x)
{
	double	step;
	double	tex_p;
	t_img	*right_dir;
	int		colour;

	right_dir = &(data->we);
	if (data->raycast.side && data->raycast.ray_dir_y < 0)
		right_dir = &(data->no);
	else if (!data->raycast.side && data->raycast.ray_dir_x > 0)
		right_dir = &(data->ea);
	else if (data->raycast.side && data->raycast.ray_dir_y > 0)
		right_dir = &(data->so);
	step = get_step(&data->raycast);
	tex_p = (((x - real_x) / WIDTH_X) - HEIGHT_Y
			/ 2 + data->raycast.lineheight / 2) * step;
	while (x <= y)
	{
		data->raycast.tex_y = (int)tex_p & 63;
		tex_p += step;
		colour = *(int *)(right_dir->addr
				+ (data->raycast.tex_y * right_dir->line_size
					+ data->raycast.tex * (right_dir->bits_per_pixel / 8)));
		ft_put_pixel_raycast(data, colour, x);
		x += WIDTH_X;
	}
}
