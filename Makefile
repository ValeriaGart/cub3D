LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

NAME = cub3D

SRCS =	src/data.c				\
		src/error.c				\
		src/free.c				\
		src/init.c				\
		src/main_act.c			\
		src/main.c				\
		src/map_check_colour.c	\
		src/map_check_info.c	\
		src/map_check_utils.c	\
		src/map_check.c			\
    	src/move_rerender.c		\
		src/path_check.c		\
		src/raycasting.c		\
		src/renders_extra.c		\
		src/real_map_check.c	\
		src/store_map.c			\
		src/signal.c			\
		src/utils.c				\
		src/window.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

all:    $(NAME)	

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git

$(NAME): $(OBJS) #$(OLINE)
		$(MAKE) all bonus -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
