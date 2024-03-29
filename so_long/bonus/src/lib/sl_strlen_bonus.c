/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:22:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:50 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	sl_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}
