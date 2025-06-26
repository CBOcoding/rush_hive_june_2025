#ifndef ARENA_H
# define ARENA_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_wordle t_wordle;

//reserving 10 MB for the arena
# define ARENA_SIZE 10485760

typedef struct s_arena
{
	char	*memory;
	size_t	used;
	size_t	capacity;
}		t_arena;

t_arena	*arena_create(size_t size);
void	*arena_alloc(t_arena *arena, size_t size);
void	arena_destroy(t_arena *arena);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
void	simple_exit(char *message, t_wordle *wordle);

#endif
