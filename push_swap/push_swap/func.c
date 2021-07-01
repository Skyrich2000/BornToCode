/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/06/28 01:05:15 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define CMD_S	0
#define CMD_P	1
#define CMD_R	2
#define CMD_RR	3

static int	print(int cmd, int stack)
{
	push(PRINT, cmd * 3 + (stack >> 1));
	return (OK);
}

int	s(int stack)
{
	if (stack == ALL)
		return (swap(A) && swap(B) && print(CMD_S, stack));
	return (swap(stack) && print(CMD_S, stack));
}

int	p(int stack)
{
	int	tmp;

	return (pop(((!stack) << 1) | HEAD, &tmp) && \
			push(stack | HEAD, tmp) && print(CMD_P, stack));
}

int	r(int stack)
{
	int	tmp;

	if (stack == ALL)
		return (pop(A | HEAD, &tmp) && push(A | TAIL, tmp) && \
				pop(B | HEAD, &tmp) && push(B | TAIL, tmp) && \
				print(CMD_R, stack));
	return (pop(stack | HEAD, &tmp) && push(stack | TAIL, tmp) && \
			print(CMD_R, stack));
}

int	rr(int stack)
{
	int	tmp;

	if (stack == ALL)
		return (pop(A | TAIL, &tmp) && push(A | HEAD, tmp) && \
				pop(B | TAIL, &tmp) && push(B | HEAD, tmp) && \
				print(CMD_RR, stack));
	return (pop(stack | TAIL, &tmp) && push(stack | HEAD, tmp) && \
			print(CMD_RR, stack));
}
