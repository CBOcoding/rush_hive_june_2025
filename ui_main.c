# define RAYGUI_IMPLEMENTATION
#include "user_interface.h"
#include "wordle.h"

int ui_main(t_wordle *wordle)
{
	SetTraceLogLevel(LOG_NONE);

	InitWindow(UI_WIDTH, UI_HEIGHT, "Wordle Assistant");
	SetTargetFPS(60);

	Font custom_font = LoadFontEx("font.ttf", 64, NULL, 0);
	SetTextureFilter(custom_font.texture, TEXTURE_FILTER_BILINEAR);


	const char *placeholder = "Word:";
	bool edit_mode = false;

	char input_word[6] = "\0";
	Input letter[5] = {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}};

	BoxColors box_colors[5] = {{LIGHTGRAY, 0}, {LIGHTGRAY, 0}, {LIGHTGRAY, 0}, {LIGHTGRAY, 0}, {LIGHTGRAY, 0}};
	Color default_colors[3] = {LIGHTGRAY, YELLOW, GREEN};

	Vector2 scroll = {0, 0};
	Rectangle view = {0};

	int line_count = wordle->data.len_matrix;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		// Draws the button
		ui_style_button();
		if (GuiButton((Rectangle){B0_X, B0_Y, B0_W, B0_H}, "Submit"))
			temporary_function(letter, wordle);

		// Draws the textbox
		ui_style_textbox();
		if (GuiTextBox((Rectangle){T0_X, T0_Y, T0_W, T0_H}, input_word, 6, edit_mode))
			edit_mode = !edit_mode;

		// Draws the placeholder text into the textbox
		if (!edit_mode && strlen(input_word) == 0)
			GuiDrawText(placeholder, (Rectangle){T0_X + 8, T0_Y, T0_W, T0_H}, TEXT_ALIGN_LEFT, GRAY);

		// Draws the scrollable panel
		ui_style_panel();
		GuiScrollPanel((Rectangle){P0_X, P0_Y, P0_W, P0_H}, "WORD SUGGESTIONS",
			(Rectangle){C0_X, C0_Y, C0_W, (line_count * 30) + 10}, &scroll, &view);

		// Draws the ADVICED WORD panel ??????
		// ui_style_button();
		// if (GuiButton((Rectangle){B0_X, B0_Y, B0_W, B0_H}, wordle->data.adviced_word))
		// adviced_word(wordle); //at the end of assistant logic BUT goes in SEG FAULT!!!!!



		// Positions the dictionary withtin the boundaries of the scrollable panel
		BeginScissorMode(view.x, view.y, view.width, view.height);
		for (int i = 0; i < wordle->data.len_matrix; i++)
			if (wordle->data.input_guesses_counter == 0)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_0[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 1)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_1[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 2)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_2[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 3)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_3[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 4)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_4[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 5)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_5[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
			else if (wordle->data.input_guesses_counter == 6)
				DrawTextEx(custom_font, wordle->data.words_in_matrix_6[i], (Vector2){P0_X + 10 + scroll.x, P0_Y + 30 + scroll.y + i * 30},
				30, 5, BLACK);
		EndScissorMode();

		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){P0_X, P0_Y, P0_W, P0_H}))
		{
			float wheel_move = GetMouseWheelMove();
			scroll.y += wheel_move * SCROLL_SPEED;
		}

		ui_detect_color_flags(letter, box_colors, default_colors);
		ui_separate_letters(input_word, letter, box_colors);

		EndDrawing();
	}

	UnloadFont(custom_font);
	CloseWindow();
	return 0;
}
