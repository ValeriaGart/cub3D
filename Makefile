LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

NAME = cub3D

SRCS =	src/data.c			\
		src/error.c			\
		src/free.c			\
		src/init.c			\
		src/main_act.c		\
		src/main.c			\
		src/map_check.c		\
		src/map_store.c		\
		src/mini_w.c		\
		src/signal.c		\
		src/utils.c			\
		src/window.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(OLINE)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz

all:    $(NAME)	

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re