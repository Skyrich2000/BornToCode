/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:49:26 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 17:53:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pre_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			if (i != j)
				ft_swap(arr + i, arr + j);
			i++;
			j--;
		}
	}
	if (left < j)
		pre_sort(arr, left, j);
	if (i < right)
		pre_sort(arr, i, right);
}

static int	get_pivot(int pos, int len, int *pivot)
{
	int		i;
	int		*arr;
	int		ret;
	t_node	*node;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (ERROR);
	i = -1;
	ret = ERROR;
	node = st()->n[pos & 2][HEAD]->link[NEXT];
	while (node->link[NEXT] && ++i < len)
	{
		arr[i] = node->data;
		node = node->link[NEXT];
		if (i > 0 && (((pos & 2) == A && arr[i - 1] > arr[i]) || \
			((pos & 2) == B && arr[i - 1] < arr[i])))
			ret = OK;
	}
	pre_sort(arr, 0, len - 1);
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
	return (ret);
}

static int	reverse(int count_ra, int count_rb)
{
	while (count_ra > 0 && count_rb > 0)
	{
		rr(ALL);
		count_ra--;
		count_rb--;
	}
	while (count_ra-- > 0)
		rr(A);
	while (count_rb-- > 0)
		rr(B);
	return (OK);
}

int			a_to_b(int len)
{
	int	pivot[2];
	int	count[12];

	if (len <= 2)
	{
		if (len == 2 && st()->n[A][HEAD]->link[NEXT]->data > \
			st()->n[A][HEAD]->link[NEXT]->link[NEXT]->data)
			s(A);
		return (OK);
	}
	if (!get_pivot(A, len, pivot))
		return (OK);
	ft_bzero(count, sizeof(int) * 12);
	while (len--)
	{
		if (st()->n[A][HEAD]->link[NEXT]->data >= pivot[1])
			count[RA] += r(A);
		else if (p(B) && ++count[PB] && \
			st()->n[B][HEAD]->link[NEXT]->data >= pivot[0])
			count[RB] += r(B);
	}
	return (reverse(count[RA], count[RB]) && \
			a_to_b(count[RA]) && b_to_a(count[RB]) && \
			b_to_a(count[PB] - count[RB]));
}

int			b_to_a(int len)
{
	int	pivot[2];
	int	count[12];

	if (len <= 2 || !get_pivot(B, len, pivot))
	{
		if (len == 2 && st()->n[B][HEAD]->link[NEXT]->data < \
			st()->n[B][HEAD]->link[NEXT]->link[NEXT]->data)
			s(B);
		while (len--)
			p(A);
		return (OK);
	}
	ft_bzero(count, sizeof(int) * 12);
	while (len--)
	{
		if (st()->n[B][HEAD]->link[NEXT]->data < pivot[0])
			count[RB] += r(B);
		else if (p(A) && ++count[PA] && \
			st()->n[A][HEAD]->link[NEXT]->data < pivot[1])
			count[RA] += r(A);
	}
	return (a_to_b(count[PA] - count[RA]) && \
			reverse(count[RA], count[RB]) && \
			a_to_b(count[RA]) && b_to_a(count[RB]));
}
