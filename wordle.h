#ifndef WORDLE_H
# define WORDLE_H

# include "arena.h"
# include "get_next_line_wordle.h"

# include <unistd.h> //write
# include <string.h> //strcmp, memset
# include <fcntl.h> //open
# include <stdlib.h> //rand()
# include <ctype.h> //tolower


# define SUCCESS 0
# define FAILURE 1

typedef struct s_data
{
	int		input_guesses_counter;//when the user input 6 guesses end the program
	int		total_file_len;
	char	*full_list_one_line;
	int		len_matrix;
	char	**words_in_matrix_0;
	char	**words_in_matrix_1;
	char	**words_in_matrix_2;
	char	**words_in_matrix_3;
	char	**words_in_matrix_4;
	char	**words_in_matrix_5;
	char	**words_in_matrix_6;
	int		j;
	int		green;
	int		yellow;
	char	forbidden_letters[27];
	char	green_lettes[6];
	char	yellow_letters[27];
	char	*adviced_word;
} t_data;


typedef struct s_wordle
{
	t_arena	*arena;
	t_data	data;
} t_wordle;

void	importing_list(char *argv, t_wordle *wordle);
char	**ft_split(char const *s, char c, t_wordle *wordle);
void	len_matrix(char **matrix, t_wordle *wordle);

#endif