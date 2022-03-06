/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:28 by ycha              #+#    #+#             */
/*   Updated: 2021/06/15 14:25:49 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static void event(t_minirt *mini)
{
	mlx_key_hook(mini->scr.win, key_hook, mini);  // esc close
	mlx_hook(mini->scr.win, 17, 0, exit_hook, 0); // x button close
}

static void setting(t_minirt *mini)
{
	t_camera *c;

	mini->scr.mlx = mlx_init();
	mini->scr.win = mlx_new_window(
		mini->scr.mlx, mini->scr.wid, mini->scr.hei, "this is minirt");
	mini->scr.anti = ANTI_ALIASING;
	c = mini->cam;
	while (c->next)
		c = c->next;
	c->next = mini->cam->next;
	mini->curr_cam = mini->cam->next;
	mini->light_toggle = 1;
	event(mini);
}

int init(t_minirt *mini)
{
	ft_memset(mini, 0, sizeof(t_minirt));
	mini->wrd = init_world();
	mini->cam = init_camera();
	mini->light = init_light();
	if (!mini->wrd || !mini->cam || !mini->light)
		return (ERROR);
	return (OK);
}

int	loop_hook(t_minirt *m)
{
	
	if (m->curr_cam->img)
		mlx_put_image_to_window(m->scr.mlx, m->scr.win, m->curr_cam->img, 0, 0);
	mlx_do_sync(m->scr.mlx);
	return 0;
}

t_minirt	*m(void)
{
	static t_minirt	mini;

	return (&mini);
}

int main(int argc, char **argv)
{
	const t_minirt *mini = m();

	if (!init(mini) || !input(argc, argv, mini))
	{
		printf("Error\n");
		return (ERROR);
	}
	setting(mini);
	draw(mini);
	mlx_loop_hook(mini->scr.mlx, loop_hook, mini);
	void *back = mlx_new_image(mini->scr.mlx, mini->scr.wid, mini->scr.hei);
	mlx_put_image_to_window(mini->scr.mlx, mini->scr.win, back, 0, 0);
	mlx_loop(mini->scr.mlx);
	return (0);
}
