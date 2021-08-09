/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/08/06 03:45:07 by ycha             ###   ########.fr       */
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
