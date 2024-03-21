LIBFT = ./libft/libft.a

NAME = cub3D

NAMEB = cub3D_bonus

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

SRCSB =	src_bonus/data.c				\
		src_bonus/error.c				\
		src_bonus/free.c				\
		src_bonus/init.c				\
		src_bonus/main_act.c			\
		src_bonus/main.c				\
		src_bonus/map_check_colour.c	\
		src_bonus/map_check_info.c		\
		src_bonus/map_check_utils.c		\
		src_bonus/map_check.c			\
    	src_bonus/move_rerender.c		\
		src_bonus/path_check.c			\
		src_bonus/raycasting.c			\
		src_bonus/renders_extra.c		\
		src_bonus/real_map_check.c		\
		src_bonus/store_map.c			\
		src_bonus/signal.c				\
		src_bonus/utils.c				\
		src_bonus/window.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all:    $(NAME)	

bonus:	$(NAMEB)

$(NAMEB): $(OBJSB)
		$(MAKE) all bonus -C ./libft
		$(CC) -o $(NAMEB) $(CFLAGS) $(OBJSB) $(LIBFT) -lm -lz -lmlx -lXext -lX11

$(NAME): $(OBJS)
		$(MAKE) all bonus -C ./libft
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) -lm -lz -lmlx -lXext -lX11

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

bonus_clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJSB)

bonus_fclean: bonus_clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAMEB)

bonus_re: bonus_fclean bonus

.PHONY: all clean fclean re bonus bonus_clean bonus_fclean bonus_re
