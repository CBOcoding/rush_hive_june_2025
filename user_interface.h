#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------

# include "wordle.h"

# include <raygui.h>
# include <raylib.h>
# include <stdio.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------

# define SCREEN_WIDTH GetScreenWidth()
# define SCREEN_HEIGHT GetScreenHeight()
# define UI_WIDTH 1000
# define UI_HEIGHT 1600

# define SCROLL_SPEED 40.0f

# define B0_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - B0_W) / 12)
# define B0_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - B0_H) - 50)
# define B0_W 200
# define B0_H 80

# define T0_X (SCREEN_WIDTH - UI_WIDTH) + 20
# define T0_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - T0_H) - 180)
# define T0_W 300
# define T0_H 80

# define L0_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - L0_W) / 2)
# define L0_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - L0_H) - 180)
# define L0_W 80
# define L0_H 80

# define L1_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - L0_W) / 2) + 110
# define L1_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - L0_H) - 180)
# define L1_W 80
# define L1_H 80

# define L2_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - L0_W) / 2) + 220
# define L2_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - L0_H) - 180)
# define L2_W 80
# define L2_H 80

# define L3_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - L0_W) / 2) + 330
# define L3_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - L0_H) - 180)
# define L3_W 80
# define L3_H 80

# define L4_X (((SCREEN_WIDTH - UI_WIDTH) / 2) + (UI_WIDTH - L0_W) / 2) + 440
# define L4_Y (((SCREEN_HEIGHT - UI_HEIGHT) / 2) + (UI_HEIGHT - L0_H) - 180)
# define L4_W 80
# define L4_H 80

# define P0_X 200
# define P0_Y 40
# define P0_W 600
# define P0_H 1200

# define C0_X 0
# define C0_Y 0
# define C0_W 580

//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------

/** Holds each individual letter with its color flag
 * @param c Letter
 * @param flag Color flag (0=LIGHTGREY, 1=YELLOW, 2=GREEN)
 */
typedef struct Input {
	char	c;
	int		flag;
} 	Input;

/** Keeps track of the color for each box
 * @param color Color of the box
 * @param pos Position of the box
 */
typedef struct BoxColors {
	Color	color;
	int		pos;
} 	BoxColors;

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

/** Suggests a word to the player
 * @param wordle Struct holding data for the main text processing logic
 * @return None
 */
char	*adviced_word(t_wordle *wordle);

/** Processes a feedback returned from the wordle game each round
 * @param letter Struct holding each individual letter with its color flag
 * @param wordle Struct holding data for the main text processing logic
 * @return None
 */
void	process_wordle_feedback(Input *letter, t_wordle *wordle);

/** Detects a mouse-click and sets color flags accordingly
 * @param letter Struct holding each individual letter with its color flag
 * @param box_colors Keeps track of the color for each box
 * @param default_colors Default choices of colors (flags)
 * @return None
 */
void	ui_detect_color_flags(Input *letter, BoxColors *box_colors, Color *default_colors);

/** Detects a mouse-scroll when over the scrollable panel and increases the scroll speed
 * @param scroll Scrol offset
 * @return None
 */
void	ui_detect_scroll(Vector2 *scroll);

/** Separates the letters of a word into individual boxes
 * @param input_word Word inserted by the user
 * @param letter Struct holding each individual letter with its color flag
 * @param box_colors Keeps track of the color for each box
 * @return None
 */
void	ui_separate_letters(char *input_word, Input *letter, BoxColors *box_colors);

/** Configurates the visuals of a button
 * @return None
 */
void	ui_style_button(void);

/** Configurates the visuals of a scrollable panel
 * @return None
 */
void	ui_style_panel(void);

/** Configurates the visuals of a textbox
 * @return None
 */
void	ui_style_textbox(void);



#endif
