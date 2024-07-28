.PHONY: all clean fclean re

NAME = fdf

FLAGS = -Wall -Wextra -Werror -Iinclude

LIBFT_ARCHIVE = include/LIBFT/libft.a
MLX_ARCHIVE = include/minilibx_macos/libmlx.a

SOURCES = src/main.c \
	src/lines.c \
	src/parse_input.c \
	src/utils.c \

OBJECTS = $(SOURCES:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE)
	gcc $(FLAGS) $(LIBFT_ARCHIVE) $(OBJECTS) $(MLX_ARCHIVE) -framework OpenGL -framework AppKit -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	cc $(FLAGS) -Imlx -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C include/LIBFT

$(MLX_ARCHIVE):
	$(MAKE) -s -C include/minilibx_macos

clean:
	rm -rf obj
	$(MAKE) fclean -s -C include/LIBFT
	$(MAKE) clean -s -C include/minilibx_macos

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -s -C include/LIBFT
	$(MAKE) clean -s -C include/minilibx_macos

re: fclean all
