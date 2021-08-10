/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:54:38 by su                #+#    #+#             */
/*   Updated: 2021/08/10 19:54:49 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_scene_rank(void)
{
	g()->asset.scene_rank = \
					add_scene(g()->asset.background_rank, \
					scene_rank_start, \
					scene_rank_controller, \
					scene_rank_ui, \
					scene_rank_end);
	return (OK);
}

void	scene_rank_start(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	g()->view.view_xview = 0;
	g()->view.view_yview = 0;
	sl_bzero(buf, BUFFER_SIZE);
	fd = open("./dashboard.rnk", O_RDONLY | O_CREAT, 0777);
	if (fd == -1 || read(fd, &buf, BUFFER_SIZE) == -1)
		return ;
	g()->global.rank_list_y = 150;
	g()->global.rank_list = sl_split(buf, '\n');
	close(fd);
}

void	scene_rank_controller(void)
{
	DEBUG && printf("scene_rank_controller start\n");
	if (keyboard_check(KEY_SPACEBAR))
	{
		scene_change(g()->asset.scene_main);
		return ;
	}
	g()->global.rank_list_y--;
	if (g()->global.rank_list_y < -g()->view.view_hview / 2 \
		-sl_split_size(g()->global.rank_list) * 40 - 100)
		scene_change(g()->asset.scene_main);
	DEBUG && printf("scene_rank_controller end\n");
}

void	scene_rank_ui(void)
{
	int		i;
	char	*line[3];

	draw_text(g()->asset.font_fat_big, "< RANK >", \
			(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
						g()->view.view_yview + g()->view.view_hview / 2 + \
				g()->global.rank_list_y - 20}, (float [2]){A_CENTER, A_CENTER});
	i = -1;
	while (g()->global.rank_list[++i])
	{
		line[0] = sl_itoa(i + 1);
		line[1] = sl_strjoin(line[0], ". ");
		line[2] = sl_strjoin(line[1], g()->global.rank_list[i]);
		draw_text(g()->asset.font_fat_small, line[2], \
			(int [2]){g()->view.view_xview + g()->view.view_wview / 2 - 200, \
						g()->view.view_yview + g()->view.view_hview / 2 + \
		g()->global.rank_list_y + (i + 1) * 40}, (float [2]){A_LEFT, A_CENTER});
		sl_free_arr3(line);
	}
	draw_img(g()->canvas.img, g()->view.view_xview, \
					g()->view.view_yview + g()->view.view_hview - 45);
	draw_text(g()->asset.font_fat_small, "PRESS SPACE TO RETURN", \
			(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
						g()->view.view_yview + g()->view.view_hview}, \
		  	(float [2]){A_CENTER, A_BOTTOM});
}

void	scene_rank_end(void)
{
	sl_free_split(g()->global.rank_list);
	g()->global.rank_list = 0;
}
