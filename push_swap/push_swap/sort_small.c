/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:02:45 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 00:02:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(void)
{
	int	num[3];

	num[0] = st()->n[A][HEAD]->link[NEXT]->data;
	num[1] = st()->n[A][HEAD]->link[NEXT]->link[NEXT]->data;
	num[2] = st()->n[A][HEAD]->link[NEXT]->link[NEXT]->link[NEXT]->data;
	if (num[0] < num[1] && num[0] < num[2] && num[1] < num[2])
		return ;
	else if (num[0] < num[1] && num[2] < num[0] && num[2] < num[1])
		rr(A);
	else if (num[1] < num[0] && num[2] < num[0] && num[1] < num[2])
		r(A);
	else
		s(A);
	sort_three();
}

void	sort_five(void)
{
	int	a_size;
	int	b_size;

	p(B);
	p(B);
	sort_three();
	if (st()->n[B][HEAD]->link[NEXT]->data >
		st()->n[B][HEAD]->link[NEXT]->link[NEXT]->data)
		s(B);
	a_size = 3;
	b_size = 2;
	while (a_size && b_size)
	{
		if (st()->n[B][HEAD]->link[NEXT]->data <
			st()->n[A][HEAD]->link[NEXT]->data)
			b_size -= p(A) && r(A);
		else
			a_size -= r(A);
	}
	while (a_size)
		a_size -= r(A);
	while (b_size)
		b_size -= p(A) && r(A);
}
