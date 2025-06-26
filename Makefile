NAME	= wordle

CC		= cc

CFLAG	= -Wall -Wextra -Werror -g

#graphic library here???

HEADERS	= 

SRCS	= main.c \

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
	@rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re