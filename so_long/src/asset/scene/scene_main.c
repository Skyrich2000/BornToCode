#include "engine.h"

int			init_scene_main()
{
	g()->asset.scene_main = add_scene(g()->asset.background_main, scene_main_start, scene_main_controller, scene_main_ui, scene_main_end);
	if (!g()->asset.scene_main)
		return (ERROR);
	return (OK);
}

void		scene_main_start()
{
	sl_bzero(&g()->global, sizeof(t_global));
	g()->view.view_xview = 0;
	g()->view.view_yview = 0;
	g()->global.time = 0;
}

void		scene_main_controller()
{
	if (DEBUG)
		printf("scene_main_controller start\n");

	g()->global.time++;

	if (keyboard_check(KEY_ENTER))
	{
		scene_change(g()->asset.scene_nick);
		return ;
	}

	if (keyboard_check(KEY_R))
	{
		scene_change(g()->asset.scene_rank);
		return ;
	}

	if (DEBUG)
		printf("scene_main_controller end\n");
}

void		scene_main_ui()
{
	if (DEBUG)
		printf("scene_main_ui start\n");
	draw_sprite(g()->asset.spr_logo, g()->asset.spr_logo->imgs->next, g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_wview / 2 - 160);

	if (g()->global.time % 80 < 40)
		draw_text(g()->asset.font_fat_small, "PRESS ENTER TO START", (int[2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_wview / 2 - 30}, (float [2]){A_CENTER, A_CENTER});
	draw_text(g()->asset.font_fat_xsmall, "PRESS R TO RANK", (int[2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_wview / 2 + 20}, (float [2]){A_CENTER, A_BOTTOM});
	if (DEBUG)
		printf("scene_main_ui end\n");
}

void		scene_main_end()
{
}
