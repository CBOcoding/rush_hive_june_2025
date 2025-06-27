#include "wordle.h"
#include "arena.h"
#include "user_interface.h"

void ui_main(t_wordle *wordle);

static void	argc_check(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		exit (EXIT_FAILURE);
	}
}

static void	check_file_name(char *argv)
{
	if (strcmp(argv, "word_list.txt") != 0)
	{
		ft_putstr_fd("Error\nProvide a proper txt\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	init_structs(t_wordle *wordle)
{
	memset(&wordle->data, 0, sizeof(wordle->data));
}

int	main(int argc, char **argv)
{
	t_wordle	wordle;
	
	(void)argv;

	argc_check(argc);
	check_file_name(argv[1]);
	wordle.arena = arena_create(ARENA_SIZE);
	if (!wordle.arena)
		return (FAILURE);
	init_structs(&wordle);
	importing_list(argv[1], &wordle);
	ui_main(&wordle);
	arena_destroy(wordle.arena);
	return (SUCCESS);
}
