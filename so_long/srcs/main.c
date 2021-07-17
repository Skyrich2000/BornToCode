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

	printf("loading done!\n");

	start_game(g()->asset.scene_play);
	return (0);
}
