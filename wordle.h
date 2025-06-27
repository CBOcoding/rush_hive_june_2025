#ifndef WORDLE_H
# define WORDLE_H

# include "arena.h"
# include "get_next_line_wordle.h"

# include <unistd.h> //write
# include <string.h> //strcmp, memset
# include <fcntl.h> //open


# define SUCCESS 0
# define FAILURE 1

typedef struct s_data
{
	int		input_guesses_counter;//when the user input 6 guesses end the program
	int		total_file_len;//
	char	*full_list_one_line;
	char	**words_in_matrix;
} t_data;


typedef struct s_wordle
{
	t_arena	*arena;
	t_data	data;
} t_wordle;

void	importing_list(char *argv, t_wordle *wordle);
char	**ft_split(char const *s, char c, t_wordle *wordle);

#endif