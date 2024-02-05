#ifndef CUB3D_H
#define CUB3D_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
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

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

typedef struct s_map
{
	char **map;
} t_map;

/* data.c */
void ft_set_data(t_data *data);

/* free.c */
int ft_free_window(t_data *data);

/* main_act.c */
int ft_main_act(t_data *data);

/* map_check.c */
int ft_map_check(char **av, t_data *data);

/* signal.c */
int handle_x(t_data *data);

/* window.c */
int ft_open_window(t_data *data);

#endif