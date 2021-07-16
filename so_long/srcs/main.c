/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:43 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 03:59:09 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int main()
{
	init_game();
	init_asset();

	t_instance *ins;

	ins = create_player_instance(50, 50);
	create_zombie_instance(450, 150);
	create_zombie_instance(450, 100);
	create_zombie_instance(450, 50);
	create_zombie_instance(450, 75);
	create_round_instance();
	printf("loading done!\n");

	start_game();

	delete_sprite(g()->asset.spr_player_idle_right);
	delete_sprite(g()->asset.spr_player_move_right);
	return (0);
}
