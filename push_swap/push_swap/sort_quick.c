/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:49:26 by ycha              #+#    #+#             */
/*   Updated: 2021/06/28 01:06:15 by echung           ###   ########.fr       */
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
		if (i > 0 && ((pos & 2) == A && arr[i - 1] > arr[i]) || \
			((pos & 2) == B && arr[i - 1] < arr[i]))
			ret = OK;
	}
	pre_sort(arr, 0, len - 1);
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
	return (ret);
}

static int	reverse(int count_RA, int count_RB)
{
	while (count_RA > 0 && count_RB > 0)
	{
		rr(ALL);
		count_RA--;
		count_RB--;
	}
	while (count_RA-- > 0)
		rr(A);
	while (count_RB-- > 0)
		rr(B);
	return (OK);
}

int			A_to_B(int len)
{
	int	pivot[2];
	int	count[12];

	if (len <= 2)
	{
		if (len == 2 && st()->n[A][HEAD]->link[NEXT]->data >
			st()->n[A][HEAD]->link[NEXT]->link[NEXT]->data)
			s(A);
		return (OK);
	}
	if (!get_pivot(A, len, pivot))
		return (OK);
	ft_bzero(count, sizeof(int) * 12);
	while (len--)
		if (st()->n[A][HEAD]->link[NEXT]->data >= pivot[1])
			r(A) && count[RA]++;
		else
		{
			p(B) && count[PB]++;
			if (st()->n[B][HEAD]->link[NEXT]->data >= pivot[0])
				r(B) && count[RB]++;
		}
	return (reverse(count[RA], count[RB]) && \
			A_to_B(count[RA]) && B_to_A(count[RB]) && \
			B_to_A(count[PB] - count[RB]));
}

int			B_to_A(int len)
{
	int	pivot[2];
	int	count[12];

	if (len <= 2 || !get_pivot(B, len, pivot))
	{
		if (len == 2 && st()->n[B][HEAD]->link[NEXT]->data <
			st()->n[B][HEAD]->link[NEXT]->link[NEXT]->data)
			s(B);
		while (len--)
			p(A);
		return (OK);
	}
	ft_bzero(count, sizeof(int) * 12);
	while (len--)
		if (st()->n[B][HEAD]->link[NEXT]->data < pivot[0])
			r(B) && count[RB]++;
		else
		{
			p(A) && count[PA]++;
			if (st()->n[A][HEAD]->link[NEXT]->data < pivot[1])
				r(A) && count[RA]++;
		}
	return (A_to_B(count[PA] - count[RA]) && \
			reverse(count[RA], count[RB]) && \
			A_to_B(count[RA]) && B_to_A(count[RB]));
}
