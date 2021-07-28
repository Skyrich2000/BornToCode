/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:43 by ycha              #+#    #+#             */
/*   Updated: 2021/07/28 23:05:16 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int	main(int ac, char **av)
{
	if (init_game() && init_asset() && init_input(ac, av))
	{
		printf("loading done!\n");
		start_game(g()->asset.scene_main);
		free_asset();
		free_input();
	}
	else
		printf("loading failed\n");
	return (0);
}
