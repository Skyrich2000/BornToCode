/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 17:36:51 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	sl_free(void *data)
{
	free(data);
}

void	sl_free_arr3(char *str[3])
{
	free(str[0]);
	free(str[1]);
	free(str[2]);
}

void	sl_free_arr5(char *str[5])
{
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str[3]);
	free(str[4]);
}
