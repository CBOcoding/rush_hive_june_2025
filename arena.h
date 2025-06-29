#ifndef ARENA_H
# define ARENA_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------

# include <stdio.h>
# include <stdlib.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------

# define ARENA_SIZE 10485760

//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------

typedef struct s_wordle t_wordle;

typedef struct s_arena
{
	char	*memory;
	size_t	used;
	size_t	capacity;
}	t_arena;

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

void	*arena_alloc(t_arena *arena, size_t size);
t_arena	*arena_create(size_t size);
void	arena_destroy(t_arena *arena);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
void	simple_exit(char *message, t_wordle *wordle);

#endif
