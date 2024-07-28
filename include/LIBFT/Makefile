.PHONY: all clean fclean re

NAME = libft.a

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -Iinclude

SOURCES	=	src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_free_array.c \
	src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_itoa.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_memset.c \
	src/ft_putchar_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_putstr_fd.c \
	src/ft_split.c \
	src/ft_strchr.c \
	src/ft_strdup.c \
	src/ft_striteri.c \
	src/ft_strjoin.c \
	src/ft_strlcat.c \
	src/ft_strlcpy.c \
	src/ft_strlen.c \
	src/ft_strmapi.c \
	src/ft_strncmp.c \
	src/ft_strnstr.c \
	src/ft_strrchr.c \
	src/ft_strtrim.c \
	src/ft_substr.c \
	src/ft_tolower.c \
	src/ft_toupper.c \
	src/ft_printf.c \
	src/ft_c.c \
	src/ft_s.c \
	src/ft_num.c \
	src/ft_u.c \
	src/ft_p.c \
	src/ft_hex.c \
	src/get_next_line.c \
	src/ft_strjoin_gnl.c \
	src/ft_free_array.c \

OBJECTS = $(SOURCES:src/%.c=obj/%.o)

# COMPILE USING THE FLAGS FOR %.o FILES WHICH HAVE CORRESPONDING %.c FILES
# $@ = target. Compiled output should be named after the target (%.o)
# $< = first prerequisite. -c $< = compile only the first prerequisite (%.c) into object file (%.o)
obj/%.o: src/%.c
	mkdir -p obj
	cc $(FLAGS) -o $@ -c $<

# MAKING ARCHIVE FILE (NAME) FROM OBJECT FILES (OBJECTS)
$(NAME):	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re:	fclean all
