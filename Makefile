# ***********************************

NAME	= push_swap
includes = -I./includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 $(includes)
obj		= $(src:%.c=%.o)

.PHONY: all clean fclean re debug sani-debug

# ***********************************

src =\
	./srcs/resolve/resolve_two_three.c \
	./srcs/resolve/resolve.c \
	./srcs/resolve/resolve_six_over.c \
	./srcs/resolve/divide.c \
	./srcs/resolve/resolve_util.c \
	./srcs/resolve/divide2.c \
	./srcs/util/util.c \
	./srcs/util/destructor.c \
	./srcs/util/arr.c \
	./srcs/util/valid_args.c \
	./srcs/util/ft_isnum.c \
	./srcs/util/is_state2.c \
	./srcs/util/is_state.c \
	./srcs/util/constructor.c \
	./srcs/main.c \
	./srcs/command/rotate.c \
	./srcs/command/push.c \
	./srcs/command/reverse_rotate.c \
	./srcs/command/swap.c \

# ***********************************

all: $(NAME)

$(NAME): $(obj)
	$(MAKE) -C lib/libft
	$(MAKE) -C lib/libex
	$(MAKE) -C lib/libbclst
	$(CC) $(CFLAGS) $(obj) lib/libft/libft.a lib/libex/libex.a lib/libbclst/libbclst.a -o $(NAME)

clean:
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C lib/libex
	$(MAKE) clean -C lib/libbclst
	$(RM) $(obj)

fclean: clean
	$(MAKE) fclean -C lib/libft
	$(MAKE) fclean -C lib/libex
	$(MAKE) fclean -C lib/libbclst
	$(RM) $(NAME)

re: fclean all

# ***********************************

debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g"

sani-debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g -fsanitize=address -fno-omit-frame-pointer"

init:
	zsh header.sh srcs includes/push_swap.h Makefile srcs
