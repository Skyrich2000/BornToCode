/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:26:53 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:08:30 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

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
