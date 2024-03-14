#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define WIDTH_X 640
# define HEIGHT_Y 480
# define WIDTH_SMALL 160
# define HEIGHT_SMALL 120

typedef struct s_map
{
	char	*nor;
	char	*sou;
	char	*eas;
	char	*wes;
	char	*ceil;
	char	*floor;
	int		ceil_colour;
	int		floor_colour;
	int		x_map;
	int		y_map;
	int		size_list;
	int		fd;
	char	**maps;
	char	**real_map;
}			t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_plr
{
	double	x;
	double	y;
	float	delta_x;
	float	delta_y;
	float	angle;
	char	direction;
}			t_plr;

typedef struct s_rc
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		lineheight;
	int		what_side;
	int		tex;
	int		tex_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwalldist;
}			t_rc;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		line_num;
	bool	smallw_enabled;
	t_img	img;
	t_img	small_w;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	t_map	*map;
	t_rc	raycast;
	t_plr	plr;
}			t_data;

/* data.c */
void		ft_set_plr(t_map *map, t_data *data);
void		ft_set_data(t_data *data);

/* error.c */
void		*ft_error_msg(char *err);

/* free.c */
void		save_free(void **ptr);
void		*ft_map_free(t_map *map, int i);
int			ft_destroy_textures(t_data *data);
int			ft_free_window(t_data *data);
int			ft_free_all(t_data *data);

// init.c
void		ft_init_raycast_loop(t_data *data, int x);
void		ft_init_raycast(t_data *data);
void		init_map(t_map *map);

/* main_act.c */
int			ft_main_act(t_data *data);
void		ft_small_w(t_data **data);

// map_check_colour.c
int			check_colour(t_map *map, int *i, int *j);

// map_check_info.c
int			assign_tex_if_unique(char **direction, t_map *map, int i);
int			check_inforhead(t_map *map, int i, int j);
int			check_four_paths(t_map *map);

// map_check_utils.c
t_list		*create_line_list(t_map *map);
int			ft_isascii_no_space(int c);
int			when_is_wrong(t_map *map, int i, int j);

// map_check.c
int			check_real_map(t_map *map);
int			ft_map_check(char **av, t_data *data);

/* move_rerender.c */
void		ft_move_sides(int keysym, t_data *data);
void		ft_direction_button(char direction, t_data *data, t_rc *raycast);

// path_check.c
int			check_path_south(t_map *map);
int			check_path_north(t_map *map);
int			check_path_west(t_map *map);
int			check_path_east(t_map *map);

/* raycasting */
int			ft_raycasting(t_data *data);

/* renders_extra.c */
int			ft_square_map(char **map, t_map *maps, t_data *data);
void		ft_put_pixel_raycast(t_data *data, int colour, int z);
void		ft_drawtheline(int x, int y, t_data *data, int colour);
void		ft_draw_pic(int x, int y, t_data *data, int real_x);

// real_map_check.c
int			first_last_line(t_map *map);
int			check_double_char(t_map *map, int i, int count);
int			check_map_char(t_map *map);
int			check_zero(t_map *map);
int			check_player(t_map *map);

/* signal.c */
int			handle_x(t_data *data);
int			handle_keypress(int keysym, t_data *data);

// store_map.c
int			check_map_empty(t_map *map, int i);
char		**get_real_map(t_map *map);

// utils.c
int			ft_emergency_exit(t_data *data);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi_from_malloc(char *str);

/* window.c */
void		ft_put_img_on_window(t_data *data, t_img *img, int x, int y);
int			ft_new_img(t_data *data, t_img *img, int x, int y);
int			ft_open_window(t_data *data);
int			ft_store_imgs(t_data *data);

#endif
