CC = gcc
CFLAGS = -Wall -Wextra #-Werror
LBFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRCS = srcs/so_long.c srcs/player_movement.c srcs/render_map.c srcs/check_errors.c srcs/sprites.c srcs/utils_1.c srcs/utils_2.c\
	srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	arch -x86_64 $(CC) $(OBJS) -o $(NAME) $(LBFLAGS) 

srcs/%.o: srcs/%.c
	arch -x86_64 $(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: clean all