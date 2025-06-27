#include "arena.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	char	*pointer;
	size_t	x;

	if (count == 0 || size == 0)
		return (malloc(1));
	total_size = count * size;
	pointer = (void *)malloc(total_size);
	x = 0;
	if (pointer == NULL)
		return (NULL);
	while (x < total_size)
	{
		pointer[x] = 0;
		x++;
	}
	return (pointer);
}

t_arena	*arena_create(size_t size)
{
	t_arena	*arena;

	arena = (t_arena *)malloc(sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->memory = (char *)ft_calloc(size, 1);
	if (!arena->memory)
	{
		free(arena);
		return (NULL);
	}
	arena->used = 0;
	arena->capacity = size;
	return (arena);
}

void	*arena_alloc(t_arena *arena, size_t size)
{
	void	*ptr;

	if (!arena || arena->used + size > arena->capacity)
		return (NULL);
	ptr = arena->memory + arena->used;
	arena->used += size;
	return (ptr);
}

void	arena_destroy(t_arena *arena)
{
	if (arena)
	{
		free(arena->memory);
		free(arena);
	}
}
