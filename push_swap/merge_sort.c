/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:49:26 by ycha              #+#    #+#             */
/*   Updated: 2021/06/21 17:37:14 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	merge_once(int n, int main, int size[2])
{
	while (size[A] && size[B])
	{
		if (st()->n[main][head]->link[next]->data < st()->n[!main][head]->link[next]->data)
			r(main) && size[main]--;
		else
			p(main) && r(main) && size[!main]--;
	}
	while (size[main])
		r(main) && size[main]--;
	while (size[!main])
		p(main) && r(main) && size[!main]--;
}

static void merge(int n)
{
	int size[2];
	int main;

	size[A] = st()->size[A];
	size[B] = st()->size[B];
	main = A;
	while (size[A] > 0 || size[B] > 0)
	{
		merge_once(n, main, (int [2]){min(n, size[A]), min(n, size[B])});
		main = !main;
		size[A] -= n;
		size[B] -= n;
	}
}

// 100				500
// 700 ->  5		5500 -> 5
// 900 ->  4		7000 -> 4
// 1100 -> 3		8500 -> 3
// 1300 -> 2		10000 -> 2
// 1500 -> 1		11500 -> 1

void	merge_sort()
{
	int i;
	int h;

	h = 1;
	i = st()->size[A];
	while (i > 1)
	{
		i /= 2;
		h *= 2;
	}
	if (h < st()->size[A])
		h *= 2;
	i = st()->size[A] / 2;
	while (i--)
		p(B);
	i = 1;
	while (i <= h)
	{
		merge(i);
		i *= 2;
	}
}
