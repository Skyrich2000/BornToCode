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

static int	print(const char *prefix, char stack)
{
	return (printf("%s%c\n", prefix, stack));
}

int			s(int stack)
{
	if (stack == ALL)
		return (swap(A << 1) && swap(B << 1) && print("s", "abs"[stack]));
	return (swap(stack << 1) && print("s", "abs"[stack]));
}

int			p(int stack)
{
	int	tmp;

	return (pop(((!stack) << 1) | head, &tmp) &&
			push((stack << 1) | head, tmp) && print("p", "ab"[stack]));
}

int			r(int stack)
{
	int	tmp;

	if (stack == ALL)
		return (pop((A << 1) | head, &tmp) && push((A << 1) | tail, tmp) &&
				pop((B << 1) | head, &tmp) && push((B << 1) | tail, tmp) &&
				print("r", "abr"[stack]));
	return (pop((stack << 1) | head, &tmp) && push((stack << 1) | tail, tmp) &&
			print("r", "abr"[stack]));
}

int			rr(int stack)
{
	int	tmp;

	if (stack == ALL)
		return (pop((A << 1) | tail, &tmp) && push((A << 1) | head, tmp) &&
				pop((B << 1) | tail, &tmp) && push((B << 1) | head, tmp) &&
				print("rr", "abr"[stack]));
	return (pop((stack << 1) | tail, &tmp) && push((stack << 1) | head, tmp) &&
			print("rr", "abr"[stack]));
}
