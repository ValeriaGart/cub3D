#ifndef CUB3D_H
#define CUB3D_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <limits.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#define DOWN_KEY 65364
#define UP_KEY 65362
#define LEFT_KEY 65361
#define RIGHT_KEY 65363

#define PI 3.1415926535
#define	WIDTH_X 640
#define	HEIGHT_Y 480
#define	WIDTH_SMALL 160
#define	HEIGHT_SMALL 120


typedef struct s_map
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*up_colour;
	char	*down_colour;
	int		ceil_colour;
	int		floor_colour;
	char 	**map;
	int		x_map;
	int		y_map;
} 			t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
} 			t_img;

typedef struct s_plr
{
	int		x;
	int		y;
	float	delta_x;
	float	delta_y;
	float	angle;
	char	direction;
} 			t_plr;

typedef struct s_data
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	int		line_num;
	bool	smallw_enabled;
	t_img	img;
	t_img	small_w;
	t_map	*map;
	t_plr	plr;
}			t_data;

/* data.c */
void    ft_set_plr(t_map *map, t_data *data);
void 	ft_set_data(t_data *data);

/* error.c */
void	*ft_error_msg(char *err);

/* free.c */
void	*ft_map_free(t_map *map);
int 	ft_free_window(t_data *data);
int		ft_free_all(t_data *data);

//init.c
int 	init_map(t_map *map);

/* main_act.c */
int 	ft_main_act(t_data *data);
int		ft_main_loop(t_data *data);
void    ft_small_w(t_data **data);

// map_check.cif (line[0] == 'R')
int		ft_map_check(int ac, char **av, t_data *data);

/* map_store.c */
//t_map	*ft_store_map(char **av, t_data *data);

/* move_rerender.c */
void	ft_direction_button(char direction, t_data *data);

/* signal.c */
int 	handle_x(t_data *data);
int		handle_keypress(int keysym, t_data *data);

//utils.c
int		ft_strcmp(char *s1, char *s2);

/* window.c */
int		ft_new_img(t_data *data, t_img *img, int x, int y);
int 	ft_open_window(t_data *data);

#endif