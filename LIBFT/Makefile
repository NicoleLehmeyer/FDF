.PHONY: all clean fclean re

NAME = libft.a

all: $(NAME)

FLAGS = -Wall -Wextra -Werror

SOURCES	=	ft_split.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_substr.c \
	ft_itoa.c \
	ft_atoi.c \
	ft_strjoin.c \
	ft_strlcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_bzero.c \
	ft_memset.c \
	ft_calloc.c \
	ft_strlcat.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf.c \
	ft_c.c \
	ft_s.c \
	ft_num.c \
	ft_u.c \
	ft_p.c \
	ft_hex.c \
	get_next_line.c \
	get_next_line_utils.c \

#BONUSES	=	ft_lstnew.c
#ft_lstadd_front.c
#ft_lstsize.c
#ft_lstlast.c
#ft_lstadd_back.c
#ft_lstdelone.c
#ft_lstclear.c
#ft_lstiter.c
#ft_lstmap.c

OBJECTS = $(SOURCES:%.c=%.o)

#BONUS_OBJECTS	= $(BONUSES:%.c=%.o)

# COMPILE USING THE FLAGS FOR %.o FILES WHICH HAVE CORRESPONDING %.c FILES
# $@ = target. Compiled output should be named after the target (%.o)
# $< = first prerequisite. -c $< = compile only the first prerequisite (%.c) into object file (%.o)
%.o: %.c
	cc $(FLAGS) -o $@ -c $<

# MAKING ARCHIVE FILE (NAME) FROM OBJECT FILES (OBJECTS)
$(NAME):	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

#bonus:	$(BONUS_OBJECTS)
#	ar rc $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS)
#$(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
