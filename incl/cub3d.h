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
#define DOWN_KEY 65364
#define UP_KEY 65362
#define LEFT_KEY 65361
#define RIGHT_KEY 65363

#define PI 3.1415926535
#define P2 PI/2
#define P3 3 * PI/2
#define DR 0.0174533
#define	WIDTH_X 640
#define	HEIGHT_Y 480
#define	WIDTH_SMALL 160
#define	HEIGHT_SMALL 120

typedef struct s_map
{
	char	*ln;
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
}			t_img;

typedef struct s_plr
{
	int		x;
	int		y;
	float	delta_x;
	float	delta_y;
	float	angle;
	char	direction;
}			t_plr;

typedef struct s_rc
{
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		side;
	int		hit;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
} 			t_rc;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		line_num;
	bool	smallw_enabled;
	t_img	img;
	t_img	small_w;
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
void		*ft_map_free(t_map *map);
int			ft_free_window(t_data *data);
int			ft_free_all(t_data *data);

//init.c
void	ft_init_raycast_loop(t_data *data, int x);
void	ft_init_raycast(t_data *data);
void 	init_map(t_map *map);


/* main_act.c */
int			ft_main_act(t_data *data);
int			ft_main_loop(t_data *data);
void		ft_small_w(t_data **data);

// map_check_colour.c
int			check_colour(t_map *map, int *i, int *j);

// map_check_info.c
int			start_check_xpm(char *line);
int			check_inforhead(t_map *map, int i, int j);
int			check_four_paths(t_map *map);

// map_check_path.c
int			check_path_south(t_map *map);
int			check_path_north(t_map *map);
int			check_path_west(t_map *map);
int			check_path_east(t_map *map);

// map_check_utils.c
t_list		*create_line_list(t_map *map);
int			ft_isascii_no_space(int c);
int			when_is_wrong(t_map *map, int i, int j);

// map_check.c
int			ft_map_check(int ac, char **av, t_data *data);

/* move_rerender.c */
void    ft_direction_button(char direction, t_data *data, t_rc *raycast);

/* raycasting */
int		ft_raycasting(t_data *data);

/* renders_extra.c */
int		ft_square_map(char **map, t_map *maps, t_data *data);
void	ft_put_pixel_raycast(t_data *data, int colour, int z);
void	ft_drawtheline(int x, int y, t_data *data, int colour);

// real_map_check.c
int			first_last_line(t_map *map);
int			check_real_map(t_map *map);

/* signal.c */
int			handle_x(t_data *data);
int			handle_keypress(int keysym, t_data *data);

// store_map.c
int			check_map_empty(t_map *map, int i);
char		**get_real_map(t_map *map);

// utils.c
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi_from_malloc(char *str);

/* window.c */
int			ft_new_img(t_data *data, t_img *img, int x, int y);
int			ft_open_window(t_data *data);

#endif
