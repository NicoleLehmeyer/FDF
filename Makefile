.PHONY: all clean fclean re

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_ARCHIVE = LIBFT/libft.a
MLX_ARCHIVE = minilibx_macos/libmlx.a

SOURCES = main.c \
	lines.c \
	parse_input.c \
	utils.c \

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE)
	gcc $(FLAGS) $(LIBFT_ARCHIVE) $(OBJECTS) $(MLX_ARCHIVE) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	cc $(FLAGS) -Imlx -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C LIBFT

$(MLX_ARCHIVE):
	$(MAKE) -s -C minilibx_macos

clean:
	rm -f $(OBJECTS)
	$(MAKE) fclean -s -C LIBFT
	$(MAKE) clean -s -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -s -C LIBFT
	$(MAKE) clean -s -C minilibx_macos

re: fclean all
