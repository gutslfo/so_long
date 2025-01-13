NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

SRCS =  main.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -lmlx -lXext -lX11
MLX_PATH = $(MLX_DIR)/libmlx.a

INCLUDES = -I$(MLX_DIR)

all: $(MLX_PATH) $(NAME)

$(MLX_PATH):
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_PATH)

re: fclean all