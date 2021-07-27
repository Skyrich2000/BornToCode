#include "engine.h"

int	cmp_rank(char *org, int new)
{
	return (sl_rev_atoi(org) > new);
}

int sl_split_size(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		;
	return (i);
}

void	scr_save_rank(char *userid, int time, int deathcount)
{
	int fd;
	int idx;
	int flag;
	char buf[BUFFER_SIZE]; // 처음에 rank file read 해오는 버퍼
	char **split;	// buf를 '\n' 기준으로 split
	char *s_step;	// step을 string으로 바꿔줌(write하려고)
	char *s_deathcount;	// deathcount를 string으로 바꿔줌

	// 1. file read
	sl_bzero(buf, BUFFER_SIZE);
	fd = open("./dashboard.rnk", O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		return ;
	if (read(fd, &buf, BUFFER_SIZE) == -1)
		return ;
	split = sl_split(buf, '\n');
	printf("-> %s\n", split[0]);
	close(fd);

	// 2. file write (O_TRUNC 해서 기존 파일 지워버림)
	fd = open("./dashboard.rnk", O_WRONLY | O_TRUNC, 0777);
	idx = -1;
	s_step = sl_itoa(time);
	s_deathcount = sl_itoa(deathcount);
	if (!*split)
	{
		write(fd, userid, sl_strlen(userid));
		write(fd, "           ", 11 - sl_strlen(userid));
		write(fd, s_step, sl_strlen(s_step));
		write(fd, "  ", 2);
		write(fd, s_deathcount, sl_strlen(s_deathcount));
		write(fd, "\n", 1);
	}
	else
	{
		flag = 0;
		while (++idx < sl_split_size(split))
		{
			if (!flag && cmp_rank(split[idx], deathcount))
			{
				write(fd, userid, sl_strlen(userid));
				write(fd, "           ", 11 - sl_strlen(userid));
				write(fd, s_step, sl_strlen(s_step));
				write(fd, "  ", 2);
				write(fd, s_deathcount, sl_strlen(s_deathcount));
				write(fd, "\n", 1);
				flag = 1;
			}
			write(fd, split[idx], sl_strlen(split[idx]));
			write(fd, "\n", 1);
		}
	}
	free(s_step);
	free(s_deathcount);
	sl_free_split(split);
	close(fd);
}


int			init_scene_rank()
{
	g()->asset.scene_rank = add_scene(g()->asset.background_rank, scene_rank_start, scene_rank_controller, scene_rank_ui, scene_rank_end);
	if (!g()->asset.scene_rank)
		return (ERROR);
	return (OK);
}

void		scene_rank_start()
{
	int		fd;
	char	buf[BUFFER_SIZE];

	g()->view.view_xview = 0;
	g()->view.view_yview = 0;
	sl_bzero(buf, BUFFER_SIZE);
	fd = open("./dashboard.rnk", O_RDONLY | O_CREAT, 0777);
	if (fd == -1 || read(fd, &buf, BUFFER_SIZE) == -1)
		return ;
	g()->global.rank_list_y = 0;
	printf("buf : %s\n", buf);
	g()->global.rank_list = sl_split(buf, '\n');
	close(fd);
}

void		scene_rank_controller()
{
	if (DEBUG)
		printf("scene_rank_controller start\n");

	if (keyboard_check(KEY_SPACEBAR))
	{
		scene_change(g()->asset.scene_main);
		return ;
	}
	g()->global.rank_list_y--;
	if (g()->global.rank_list_y < -g()->view.view_hview / 2 -sl_split_size(g()->global.rank_list) * 40 - 100)
	{
		scene_change(g()->asset.scene_main);
	}

	if (DEBUG)
		printf("scene_rank_controller end\n");
}

void scene_rank_ui()
{
	int i;
	char *line[2];

	if (DEBUG)
		printf("scene_rank_ui start\n");

	draw_text(g()->asset.font_fat_big,
			  "< RANK >",
			  (int [2]){ g()->view.view_xview + g()->view.view_wview / 2,
						g()->view.view_yview + g()->view.view_hview / 2 + g()->global.rank_list_y - 20},
			  (float [2]){ A_CENTER, A_CENTER });
	i = -1;
	while (g()->global.rank_list[++i])
	{
		line[0] = sl_strjoin(sl_itoa(i + 1), ". ");
		line[1] = sl_strjoin(line[0], g()->global.rank_list[i]);
		draw_text(g()->asset.font_fat_small,
				line[1],
				(int [2]){ g()->view.view_xview + g()->view.view_wview / 2 - 200,
							g()->view.view_yview + g()->view.view_hview / 2 + g()->global.rank_list_y + (i + 1) * 40},
				(float [2]){A_LEFT, A_CENTER});
		free(line[0]);
		free(line[1]);
	}
	draw_img(g()->canvas.img, g()->view.view_xview, g()->view.view_yview + g()->view.view_hview - 45);
	draw_text(g()->asset.font_fat_small,
			  "PRESS SPACE TO RETURN",
			  (int [2]){ g()->view.view_xview + g()->view.view_wview / 2,
						g()->view.view_yview + g()->view.view_hview},
			  (float [2]){ A_CENTER, A_BOTTOM });
	if (DEBUG)
		printf("scene_rank_ui end\n");
}

void		scene_rank_end()
{
	sl_free_split(g()->global.rank_list);
	g()->global.rank_list = 0;
}
