#include "engine.h"

int			init_scene_nickname()
{
	g()->asset.scene_nickname = add_scene(g()->asset.background_menu, scene_nickname_start, scene_nickname_controller, scene_nickname_ui, scene_nickname_end);
	if (!g()->asset.scene_nickname)
		return (ERROR);
	return (OK);
}

void		scene_nickname_start()
{
	g()->global.nick_index = 0;
	sl_memcpy(g()->global.nick, "        ", 9);
}

void		scene_nickname_controller()
{
	int i;
	char *ascii;
	static char prev[50];
	static char prev_backspace;

	ascii = (char [50]){'A', 'S', 'D', 'F', 'H', 'G', 'Z', 'X', 'C', 'V', '\0', 'B', 'Q', 'W', 'E', 'R', 'Y', 'T', '1', '2', '3', '4', '6', '5', '=', '9', '7', '-', '8', '0', '}', 'O', 'U', '{', 'I', 'P', '\0', 'L', 'J', '\"', 'K', ':', '\0', '\0', '?', 'N', 'M', '.', '\0', '\0'};

	if (DEBUG)
		printf("scene_nickname_controller start\n");

	g()->global.time++;
	if (g()->global.time > 20 && g()->global.nick_index < NICK_SIZE)
	{
		g()->global.time = 0;
		if (g()->global.nick[g()->global.nick_index] == '_')
			g()->global.nick[g()->global.nick_index] = ' ';
		else
			g()->global.nick[g()->global.nick_index] = '_';
	}

	i = -1;
	while (++i < 50)
	{
		if (keyboard_check(KEY_ENTER) && g()->global.nick_index)
		{
			if (g()->global.nick[g()->global.nick_index] == '_')
				g()->global.nick[g()->global.nick_index] = ' ';
			scene_change(g()->asset.scene_play);
		}
		else if (keyboard_check(KEY_BACKSPACE) && !prev_backspace)
		{
			if (g()->global.nick_index <= 0)
				printf("\a\n");
			else
			{
				if (g()->global.nick[g()->global.nick_index] == '_')
					g()->global.nick[g()->global.nick_index] = ' ';
				g()->global.nick[--g()->global.nick_index] = ' ';
			}
			break;
		}
		else if (keyboard_check(i) && !prev[i] && ascii[i] != '\0')
		{
			if (g()->global.nick_index >= NICK_SIZE)
				printf("\a\n");
			else
				g() -> global.nick[g()->global.nick_index++] = ascii[i];
		}
	}

	i = -1;
	while (++i < 50)
	{
		prev[i] = keyboard_check(i);
	}
	prev_backspace = keyboard_check(KEY_BACKSPACE);

	if (DEBUG)
		printf("scene_nickname_controller end\n");
}

void		scene_nickname_ui()
{
	draw_text(g()->asset.font_fat_big, \
		g()->global.nick, \
		(int [2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_hview / 2}, \
		(float [2]){A_CENTER, A_CENTER});
}

void		scene_nickname_end()
{
	destroy_all_instance();
}
