#include "user_interface.h"

void	ui_detect_scroll(Vector2 *scroll)
{
	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){P0_X, P0_Y, P0_W, P0_H}))
	{
		float wheel_move = GetMouseWheelMove();
		scroll->y += wheel_move * SCROLL_SPEED;
	}
}

void	ui_detect_color_flags(Input *letter, BoxColors *box_colors, Color *default_colors)
{
	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){L0_X, L0_Y, L0_W, L0_H}) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			box_colors[0].pos++;
			if (box_colors[0].pos == 3)
				box_colors[0].pos = 0;
			box_colors[0].color = default_colors[box_colors[0].pos];
			letter[0].flag = box_colors[0].pos;

		}

	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){L1_X, L1_Y, L1_W, L1_H}) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			box_colors[1].pos++;
			if (box_colors[1].pos == 3)
				box_colors[1].pos = 0;
			box_colors[1].color = default_colors[box_colors[1].pos];
			letter[1].flag = box_colors[1].pos;

		}

	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){L2_X, L2_Y, L2_W, L2_H}) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			box_colors[2].pos++;
			if (box_colors[2].pos == 3)
				box_colors[2].pos = 0;
			box_colors[2].color = default_colors[box_colors[2].pos];
			letter[2].flag = box_colors[2].pos;

		}

	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){L3_X, L3_Y, L3_W, L3_H}) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			box_colors[3].pos++;
			if (box_colors[3].pos == 3)
				box_colors[3].pos = 0;
			box_colors[3].color = default_colors[box_colors[3].pos];
			letter[3].flag = box_colors[3].pos;

		}

	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){L4_X, L4_Y, L4_W, L4_H}) &&
		IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			box_colors[4].pos++;
			if (box_colors[4].pos == 3)
				box_colors[4].pos = 0;
			box_colors[4].color = default_colors[box_colors[4].pos];
			letter[4].flag = box_colors[4].pos;
		}
}

void	ui_separate_letters(char *input_word, Input *letter, BoxColors *box_colors)
{
	letter[0].c = input_word[0];
	letter[1].c = input_word[1];
	letter[2].c = input_word[2];
	letter[3].c = input_word[3];
	letter[4].c = input_word[4];

	char letter_string0[2] = {letter[0].c, '\0'};
	char letter_string1[2] = {letter[1].c, '\0'};
	char letter_string2[2] = {letter[2].c, '\0'};
	char letter_string3[2] = {letter[3].c, '\0'};
	char letter_string4[2] = {letter[4].c, '\0'};

	DrawRectangle(L0_X, L0_Y, L0_W, L0_H, box_colors[0].color);
	DrawRectangle(L1_X, L1_Y, L1_W, L1_H, box_colors[1].color);
	DrawRectangle(L2_X, L2_Y, L2_W, L2_H, box_colors[2].color);
	DrawRectangle(L3_X, L3_Y, L3_W, L3_H, box_colors[3].color);
	DrawRectangle(L4_X, L4_Y, L4_W, L4_H, box_colors[4].color);

	DrawText(letter_string0, L0_X + 25, L0_Y + 10, 60, BLACK);
	DrawText(letter_string1, L0_X + 135, L0_Y + 10, 60, BLACK);
	DrawText(letter_string2, L0_X + 245, L0_Y + 10, 60, BLACK);
	DrawText(letter_string3, L0_X + 355, L0_Y + 10, 60, BLACK);
	DrawText(letter_string4, L0_X + 465, L0_Y + 10, 60, BLACK);
}
