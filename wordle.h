#ifndef WORDLE_H
# define WORDLE_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------

# include "arena.h"
# include "get_next_line_wordle.h"

# include <ctype.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------

# define SUCCESS 0
# define FAILURE 1

//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------

typedef struct s_data
{
	char	*full_list_one_line;
	char	**words_in_matrix_0;
	char	**words_in_matrix_1;
	char	**words_in_matrix_2;
	char	**words_in_matrix_3;
	char	**words_in_matrix_4;
	char	**words_in_matrix_5;
	char	**words_in_matrix_6;
	char	forbidden_letters[27];
	char	green_lettes[6];
	char	yellow_letters[27];
	char	*adviced_word;
	int		input_guesses_counter;
	int		j;
	int		len_matrix;
	int		total_file_len;
	int		green;
	int		yellow;
}	t_data;

typedef struct s_wordle
{
	t_arena	*arena;
	t_data	data;
}	t_wordle;

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

char	**ft_split(char const *s, char c, t_wordle *wordle);
void	importing_list(char *argv, t_wordle *wordle);
void	len_matrix(char **matrix, t_wordle *wordle);
void	ui_main(t_wordle *wordle);

#endif
