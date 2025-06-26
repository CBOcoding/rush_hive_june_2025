#ifndef WORDLE_H
# define WORDLE_H

# include "arena.h"

# include <unistd.h> //write
#  include <string.h> //strcmp, memset

# define SUCCESS 0
# define FAILURE 1

typedef struct s_data
{
	int	test;
	int test2;
} t_data;


typedef struct s_wordle
{
	t_arena	*arena;
	t_data	data;
} t_wordle;

#endif