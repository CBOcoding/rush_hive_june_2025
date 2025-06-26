#ifndef WORDLE_H
# define WORDLE_H

# include "arena.h"

# include <unistd.h> //write
#  include <string.h> //strcmp, memset

# define SUCCESS 0
# define FAILURE 1

typedef struct s_data
{
	int		input_guesses_counter;//when the user input 6 guesses end the program
	int		test2;//
	char	*full_list_one_line;
	char	**words_in_matrix;
} t_data;


typedef struct s_wordle
{
	t_arena	*arena;
	t_data	data;
} t_wordle;

void	importing_list(char *argv, t_wordle *wordle);

#endif