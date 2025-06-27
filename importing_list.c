#include "wordle.h"

static void	total_file_len_calculation(int fd, t_wordle *wordle, t_data *data)
{
	char	*line;
	int		char_in_line;

	line = get_next_line(fd, wordle);
	char_in_line = 0;
	if (line == NULL)
		simple_exit("Error\nNULL line\n", wordle);
	while (line != NULL)
	{
		char_in_line = ft_strlen_gnl(line);
		data->total_file_len = data->total_file_len + char_in_line;
		line = get_next_line(fd, wordle);
	}
	if (data->total_file_len == 0)
		simple_exit("Error\nEmpty file\n", wordle);
}

void	filling_line(char *file_name, t_wordle *wordle)
{
	int		fd;
	ssize_t	bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		simple_exit("Error\nError on opening the map\n", wordle);
	bytes_read = read(fd, wordle->data.full_list_one_line,
			wordle->data.total_file_len);
	if (bytes_read == -1)
	{
		close(fd);
		simple_exit("Error\nError on reading the map\n", wordle);
	}
	wordle->data.full_list_one_line[wordle->data.total_file_len] = '\0';
	close(fd);
}

void	len_matrix(char **matrix, t_wordle *wordle)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	wordle->data.len_matrix = i;
}

void	filling_words_in_matrix(t_wordle *wordle)
{
	wordle->data.words_in_matrix_0 = ft_split(wordle->data.full_list_one_line, '\n', wordle);
	len_matrix(wordle->data.words_in_matrix_0, wordle);
}

void	importing_list(char *argv, t_wordle *wordle)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		simple_exit("Error\nError on opening the map\n", wordle);
	total_file_len_calculation(fd, wordle, &wordle->data);
	close (fd);
	wordle->data.full_list_one_line = arena_alloc(wordle->arena,
			wordle->data.total_file_len + 1);
	filling_line(argv, wordle);
	filling_words_in_matrix(wordle);
}
