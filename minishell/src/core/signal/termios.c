/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:44:39 by ycha              #+#    #+#             */
/*   Updated: 2021/12/13 13:44:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "core/signal.h"

void	termios_echoctl_on(void)
{
	struct termios	attributes;

	tcgetattr(STDOUT_FILENO, &attributes);
	attributes.c_lflag |= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSANOW, &attributes);
}

void	termios_echoctl_off(void)
{
	struct termios	attributes;

	tcgetattr(STDOUT_FILENO, &attributes);
	attributes.c_lflag &= (~ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &attributes);
}
