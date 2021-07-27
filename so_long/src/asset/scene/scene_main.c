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
	int i;
	int j;
	t_instance *ins;
	int out_dir[20];
	char	map[7][15] = {
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000"
	};
	g()->global.player = create_player_instance(2 * 32, 5 * 32, S_STRAIGHT);
}

void		scene_main_controller()
{
	if (DEBUG)
		printf("scene_main_controller start\n");

	if (keyboard_check(KEY_SPACEBAR) && on_triger)
		// go to next scene

	if (DEBUG)
		printf("scene_main_controller end\n");
}

void		scene_main_ui()
{
	char	*str[2];

	draw_text(g()->asset.font_fat_big, " V E N E V ", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_CENTER, A_UP});
	draw_text(g()->asset.font_fat_big, "[ S T A R T ]", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_CENTER, A_UP});
	draw_text(g()->asset.font_fat_big, "[  R A N K  ]", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_CENTER, A_UP});

	if (g()->global.state == S_READY)
		draw_sprite(g()->asset.spr_light_dark, g()->asset.spr_light_dark->imgs->next, g()->global.mainer->x, g()->global.mainer->y);
	if (g()->global.state == S_STRAIGHT)
		draw_sprite(g()->asset.spr_light, g()->asset.spr_light->imgs->next, g()->global.mainer->x, g()->global.mainer->y);
}

void		scene_main_end()
{
	t_list		*node;
	t_instance	*ins;
	int			*type;
	int			i;

	type = (int [3]){PLAYER, ZOMBIE, BOX};
	i = -1;
	while (++i < 3)
	{
		node = g()->instances[type[i]]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			free_list(scr_get_route(ins, type[i]), sl_free);
		}
	}
	destroy_all_instance();
}
