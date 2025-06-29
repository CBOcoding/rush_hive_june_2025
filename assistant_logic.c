#include "user_interface.h"
#include "wordle.h"

static int	has_duplicate_letters(char *word);
static void	reset_colors_partial(BoxColors *box_colors, Input *letter);
static void	reset_colors_all(BoxColors *box_colors, Input *letter);

void	process_wordle_feedback(Input *letter, t_wordle *wordle, BoxColors *box_colors)
{
	int	x;
	int	y;
	int	z;
	int	char_check;
	int	forbidden_index;

	wordle->data.input_guesses_counter += 1;
	wordle->data.forbidden_letters[26] = 0;
	wordle->data.green_lettes[5] = 0;
	wordle->data.yellow_letters[26] = 0;
	x = 0;
	z = 0;

	while (z < 5)
	{
		if (letter[z].flag == 2)
		{
			char_check = 0;
			while (char_check < wordle->data.green)
			{
				if (wordle->data.green_lettes[char_check] == letter[z].c)
				goto next_letter1;
				char_check++;
			}
			if (letter[z].c )
			wordle->data.green_lettes[wordle->data.green] = letter[z].c;
			wordle->data.green += 1;
		}
		next_letter1:
		z++;
	}

	z = 0;
	while (z < 5)
	{
		if (letter[z].flag == 1)
		{
			char_check = 0;
			while (char_check < wordle->data.yellow)
			{
				if (wordle->data.yellow_letters[char_check] == letter[z].c)
				goto next_letter3;
				char_check++;
			}
			if (letter[z].c )
			wordle->data.yellow_letters[wordle->data.yellow] = letter[z].c;
			wordle->data.yellow += 1;
		}
		next_letter3:
		z++;
	}
	
	z = 0;
	while (z < 5)
	{
		if (letter[z].flag == 0)
		{
			char_check = 0;
			while (char_check < wordle->data.green)
			{
				if (wordle->data.green_lettes[char_check] == letter[z].c)
				goto next_letter2;
				char_check++;
			}
			char_check = 0;
			while (char_check < wordle->data.yellow)
			{
				if (wordle->data.yellow_letters[char_check] == letter[z].c)
				goto next_letter2;
				char_check++;
			}
			char_check = 0;
			while (char_check < wordle->data.j)
			{
				if (wordle->data.forbidden_letters[char_check] == letter[z].c)
				goto next_letter2;
				char_check++;
			}
			if (letter[z].c )
			wordle->data.forbidden_letters[wordle->data.j] = letter[z].c;
			wordle->data.j += 1;
		}
		next_letter2:
		z++;
	}

	z = 0;
	if (wordle->data.input_guesses_counter == 1)
	{
		len_matrix(wordle->data.words_in_matrix_0, wordle);
		wordle->data.words_in_matrix_1 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_0[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_0[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_0[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word1;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_0[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word1;
				if (wordle->data.words_in_matrix_0[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word1;
				y += 1;
			}
			wordle->data.words_in_matrix_1[z] = wordle->data.words_in_matrix_0[x];
			z += 1;
			next_word1:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_1, wordle);
	}
	else if (wordle->data.input_guesses_counter == 2)
		{
		wordle->data.words_in_matrix_2 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_1[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_1[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_1[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word2;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_1[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word2;
				if (wordle->data.words_in_matrix_1[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word2;
				y += 1;
			}
			wordle->data.words_in_matrix_2[z] = wordle->data.words_in_matrix_1[x];
			z += 1;
			next_word2:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_2, wordle);
	}
	else if (wordle->data.input_guesses_counter == 3)
		{
		wordle->data.words_in_matrix_3 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_2[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_2[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_2[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word3;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_2[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word3;
				if (wordle->data.words_in_matrix_2[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word3;
				y += 1;
			}
			wordle->data.words_in_matrix_3[z] = wordle->data.words_in_matrix_2[x];
			z += 1;
			next_word3:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_3, wordle);
	}
	else if (wordle->data.input_guesses_counter == 4)
		{
		wordle->data.words_in_matrix_4 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_3[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_3[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_3[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word4;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_3[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word4;
				if (wordle->data.words_in_matrix_3[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word4;
				y += 1;
			}
			wordle->data.words_in_matrix_4[z] = wordle->data.words_in_matrix_3[x];
			z += 1;
			next_word4:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_4, wordle);
	}
	else if (wordle->data.input_guesses_counter == 5)
		{
		wordle->data.words_in_matrix_5 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_4[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_4[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_4[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word5;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_4[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word5;
				if (wordle->data.words_in_matrix_4[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word5;
				y += 1;
			}
			wordle->data.words_in_matrix_5[z] = wordle->data.words_in_matrix_4[x];
			z += 1;
			next_word5:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_5, wordle);
	}
	else if (wordle->data.input_guesses_counter == 6)
		{
		wordle->data.words_in_matrix_6 = arena_alloc(wordle->arena, (wordle->data.len_matrix + 1) * sizeof(char *));
		while (wordle->data.words_in_matrix_5[x])
		{
			y = 0;
			while (wordle->data.words_in_matrix_5[x][y])
			{
				forbidden_index = 0;
				while (forbidden_index < wordle->data.j)
				{
					if(wordle->data.words_in_matrix_5[x][y] == wordle->data.forbidden_letters[forbidden_index])
						goto next_word6;
					forbidden_index += 1;
				}
				if (wordle->data.words_in_matrix_5[x][y] == letter[y].c && letter[y].flag == 1)
					goto next_word6;
				if (wordle->data.words_in_matrix_5[x][y] != letter[y].c && letter[y].flag == 2)
					goto next_word6;
				y += 1;
			}
			wordle->data.words_in_matrix_6[z] = wordle->data.words_in_matrix_5[x];
			z += 1;
			next_word6:
			x++;
		}
		len_matrix(wordle->data.words_in_matrix_6, wordle);
	}
	else
	{
		wordle->data.words_in_matrix_6[0] = "GAME OVER! PRESS RESET";
		wordle->data.len_matrix = 1;
		return ;
	}
	
	reset_colors_partial(box_colors, letter);
	wordle->data.adviced_word = adviced_word(wordle);
}

char	*adviced_word(t_wordle *wordle)
{
	int	attempt;
	int	index;

	if (wordle->data.input_guesses_counter == 0)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_0[index]))
				return (wordle->data.words_in_matrix_0[index]);
		}
		return wordle->data.words_in_matrix_0[index];
	}
	else if (wordle->data.input_guesses_counter == 1)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_1[index]))
				return (wordle->data.words_in_matrix_1[index]);
		}
		return wordle->data.words_in_matrix_1[index];
	}
	else if (wordle->data.input_guesses_counter == 2)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_2[index]))
				return (wordle->data.words_in_matrix_2[index]);
		}
		return wordle->data.words_in_matrix_2[index];
	}
	else if (wordle->data.input_guesses_counter == 3)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_3[index]))
				return (wordle->data.words_in_matrix_3[index]);
		}
		return wordle->data.words_in_matrix_3[index];
	}
	else if (wordle->data.input_guesses_counter == 4)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_4[index]))
				return (wordle->data.words_in_matrix_4[index]);
		}
		return wordle->data.words_in_matrix_4[index];
	}	
	else if (wordle->data.input_guesses_counter == 5)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_5[index]))
				return (wordle->data.words_in_matrix_5[index]);
		}
		return wordle->data.words_in_matrix_5[index];
	}
	else if (wordle->data.input_guesses_counter == 6)
	{
		attempt = wordle->data.len_matrix;
		while (attempt--)
		{
			index = rand() % wordle->data.len_matrix;
			if (!has_duplicate_letters(wordle->data.words_in_matrix_6[index]))
				return (wordle->data.words_in_matrix_6[index]);
		}
		return wordle->data.words_in_matrix_6[index];
	}
	return NULL;
}

static int	has_duplicate_letters(char *word)
{
	int	index;
	int seen[26] = {0};
	for (int i = 0; i < 5; i++) 
	{
		index = tolower(word[i]) - 'a';
		if (index < 0 || index >= 26)
			continue;
		if (seen[index])
			return 1;
		seen[index] = 1;
	}
	return 0;
}

void	reset_state(t_wordle *wordle, BoxColors *box_colors, Input *letter)
{
	wordle->data.input_guesses_counter = 0;
	len_matrix(wordle->data.words_in_matrix_0, wordle);
	wordle->data.forbidden_letters[26] = 0;
	wordle->data.green_lettes[5] = 0;
	wordle->data.yellow_letters[26] = 0;
	wordle->data.j = 0;
	wordle->data.adviced_word = adviced_word(wordle);
	reset_colors_all(box_colors, letter);
}

static void	reset_colors_partial(BoxColors *box_colors, Input *letter)
{
	for (int i = 0; i < 5; i++)
	{
		if (box_colors[i].pos != 2)
		{
			box_colors[i].color = LIGHTGRAY;
			box_colors[i].pos = 0;
			letter[i].flag = 0;
		}
	}
}

static void	reset_colors_all(BoxColors *box_colors, Input *letter)
{
	for (int i = 0; i < 5; i++)
	{
		box_colors[i].color = LIGHTGRAY;
		box_colors[i].pos = 0;
		letter[i].flag = 0;
	}
}
