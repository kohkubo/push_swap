# ***********************************

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 -g -fsanitize=address
obj		= $(src:%.c=%.o)

.PHONY: all clean fclean re debug sani-debug

# ***********************************

src =\
	./srcs/rotate.c \
	./srcs/push.c \
	./srcs/main.c \
	./srcs/reverse_rotate.c \
	./srcs/valid_args.c \
	./srcs/ft_isnum.c \
	./srcs/swap.c \

# ***********************************

all: $(NAME)

$(NAME): $(obj)
	$(MAKE) -C lib/libft
	$(MAKE) -C lib/libex
	$(MAKE) -C lib/libbclst
	$(CC) $(CFLAGS) $(obj) lib/libft/libft.a lib/libex/libex.a lib/libbclst/libbclst.a -o $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ***********************************

debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g"

sani-debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g -fsanitize=address"

init:
	zsh header.sh srcs includes/push_swap.h Makefile srcs