# ***********************************

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 -g -fsanitize=address -fno-omit-frame-pointer
obj		= $(src:%.c=%.o)

.PHONY: all clean fclean re debug sani-debug

# ***********************************

src =\
	./srcs/resolve_asc.c \
	./srcs/resolve_desc.c \
	./srcs/util.c \
	./srcs/print.c \
	./srcs/rotate.c \
	./srcs/push.c \
	./srcs/resolve.c \
	./srcs/destructor.c \
	./srcs/main.c \
	./srcs/arr.c \
	./srcs/divide.c \
	./srcs/reverse_rotate.c \
	./srcs/valid_args.c \
	./srcs/ft_isnum.c \
	./srcs/swap.c \
	./srcs/constructor.c \

# ***********************************

all: $(NAME)

$(NAME): $(obj)
	@$(MAKE) -C lib/libft
	@$(MAKE) -C lib/libex
	@$(MAKE) -C lib/libbclst
	@$(CC) $(CFLAGS) $(obj) lib/libft/libft.a lib/libex/libex.a lib/libbclst/libbclst.a -o $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ***********************************

debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g"

sani-debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g -fsanitize=address -fno-omit-frame-pointer"

init:
	zsh header.sh srcs includes/push_swap.h Makefile srcs