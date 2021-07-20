/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:43 by ycha              #+#    #+#             */
/*   Updated: 2021/07/20 17:01:18 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int main()
{
	if (init_game() && init_asset())
	{
		printf("loading done!\n");
		start_game(g()->asset.scene_play);
	}
	else
		printf("loading failed\n");
	return (0);
}
