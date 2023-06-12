NAME = so_long

SRC = 0_get_next_line.c \
	1_input_handling.c \
	2_map_error_handling.c \
	3_map_creation.c \
	4_player_moves.c \
	5_map_build.c \
	6_keyhook.c \
	7_init_game.c \
	8_end_game.c \
	9_enemy_move.c \
	10_window_image_handling.c

OBJECTS = $(SRC:.c=.o)
LIBFT_OBJ = ./include/libft/libft.a
MLX = ./include/mlx/libmlx.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -L ./include/mlx -lmlx -L ./include/libft -lft -framework OpenGl -framework AppKit


$(NAME): $(MLX) $(OBJECTS) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(MLX):
	make --directory=./include/mlx

$(LIBFT_OBJ):
	make --directory=./include/libft

all: $(NAME)

clean:
	rm -f $(OBJECTS)
	make clean -C ./include/libft
	make clean -C ./include/mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./include/libft

re: fclean all

.PHONY: all clean fclean re