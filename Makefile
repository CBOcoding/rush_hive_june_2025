NAME	= wordle

CC		= cc

CFLAG	= -Wall -Wextra -Werror -g -fsanitize=address

#graphic library here???

HEADERS	= -I.

SRCS	=	main.c \
			arena_simple_exit.c \
			arena_utils_01.c \
			importing_list.c \
			file_check.c \


OBJS	=$(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re