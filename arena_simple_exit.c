#include "wordle.h"

void	simple_exit(char *message, t_wordle *wordle)
{
	ft_putstr_fd(message, 2);
	arena_destroy(wordle->arena);
	exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *str, int fd)
{
	ssize_t	bytes_written;

	if (!str)
		return ;
	bytes_written = write(fd, str, ft_strlen(str));
	if (bytes_written == -1)
		perror("write");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
