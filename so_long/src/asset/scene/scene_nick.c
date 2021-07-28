#include "engine.h"

int			init_scene_nick()
{
	g()->asset.scene_nick = add_scene(g()->asset.background_nick, scene_nick_start, scene_nick_controller, scene_nick_ui, scene_nick_end);
	if (!g()->asset.scene_nick)
		return (ERROR);
	return (OK);
}

void		scene_nick_start()
{
	g()->view.view_xview = 0;
	g()->view.view_yview = 0;
	g()->global.nick_index = 0;
	sl_memcpy(g()->global.nick, "                 ", NICK_SIZE);
	g()->global.nick[NICK_SIZE] = '\0';
}

void		scene_nick_controller()
{
	int i;
	char *ascii;
	static char prev[50];
	static char prev_backspace;

	ascii = (char [50]){'A', 'S', 'D', 'F', 'H', 'G', 'Z', 'X', 'C', 'V', '\0', 'B', 'Q', 'W', 'E', 'R', 'Y', 'T', '1', '2', '3', '4', '6', '5', '\0', '9', '7', '-', '8', '0', '}', 'O', 'U', '{', 'I', 'P', '\0', 'L', 'J', '\"', 'K', ':', '\0', '\0', '?', 'N', 'M', '.', '\0', '\0'};

	if (DEBUG)
		printf("scene_nick_controller start\n");

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
			printf("asdf\n");
			scene_change(g()->asset.scene_play);
			printf("asdf end\n");
			return ;
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
		printf("scene_nick_controller end\n");
}

void		scene_nick_ui()
{
	draw_text(g()->asset.font_fat_small, \
		"INPUT YOUR NICKNAME", \
		(int [2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_hview / 2 - 40}, \
		(float [2]){A_CENTER, A_CENTER});
	draw_text(g()->asset.font_fat_big, \
		g()->global.nick, \
		(int [2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_hview / 2}, \
		(float [2]){A_CENTER, A_CENTER});
}

void		scene_nick_end()
{
	destroy_all_instance();
}
