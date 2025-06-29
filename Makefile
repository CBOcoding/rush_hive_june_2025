NAME	=	wordle

CC		=	cc

CFLAGS	=	-Wall -Wextra
LFLAGS	=	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
HEADERS	=	-I.

SRCS	=	./gnl_wordle/get_next_line_utils_wordle.c \
			./gnl_wordle/get_next_line_wordle.c \
			assistant_logic.c \
			arena_simple_exit.c \
			arena_utils_01.c \
			importing_list.c \
			main.c \
			ui_main.c \
			ui_process_input.c \
			ui_style.c \
			utils_functions_01.c \

OBJS	=	$(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LFLAGS) $(HEADERS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
