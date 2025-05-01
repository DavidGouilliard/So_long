SRC = main.c utils.c utils2.c parsing.c flood_fill.c game_loop_utils.c
OBJ = $(SRC:.c=.o)


ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT = ./libft/libft.a
FT_PRINT = ./printf/libftprintf.a
MLX_FLAGS = -L/usr/lib/X11 -lXext -lX11


ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

NAME = so_long

all: $(LIBFT) $(FT_PRINT) $(MLX_LIB) $(NAME)

.c.o:
	$(CC) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINT) $(MLX_LIB) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C ./libft

$(FT_PRINT):
	@make -C ./printf

clean:
	rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./printf

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./printf

re: fclean all

.PHONY: all clean fclean re
