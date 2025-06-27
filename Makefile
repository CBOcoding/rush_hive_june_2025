CC = cc
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = assistant

HDR = user_interface.h
SRCS = $(wildcard *.c)

all: $(TARGET) $(HDR)
	@./$(TARGET)

$(TARGET): $(SRCS) $(HDR)
	@$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

clean:
	@rm -f $(TARGET)

re: clean all

.PHONY: all clean re run
NAME	= wordle

CC		= cc

CFLAG	= -Wall -Wextra -Werror -g -fsanitize=address

HEADERS	= -I.

SRCS	=	main.c \
			arena_simple_exit.c \
			arena_utils_01.c \
			importing_list.c \
			./gnl_wordle/get_next_line_wordle.c \
			./gnl_wordle/get_next_line_utils_wordle.c \
			utils_functions_01.c \
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
