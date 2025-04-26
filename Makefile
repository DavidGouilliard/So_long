SRC = main.c utils.c parsing.c flood_fill.c
OBJ = $(SRC:.c=.o)
INCLUDES = -I/usr/include -Imlx
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT = ./libft/libft.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

all: $(LIBFT) $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C ./libft

clean:
	rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
