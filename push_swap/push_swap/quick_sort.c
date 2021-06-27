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

#define ra 0
#define rb 1
#define pb 2
#define pa 2

static void	pre_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int pivot;

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

static int get_pivot(int pos, int len, int *pivot)
{
	int		i;
	int		*arr;
	int		flag;
	t_node	*node;

	arr = malloc(sizeof(int) * len);
	i = 0;
	flag = 0;
	node = st()->n[pos >> 1][head]->link[next];
	while(node->link[next] && i < len)
	{
		arr[i++] = node->data;
		node = node->link[next];
		if (i > 0 && arr[i - 2] > arr[i - 1])
			flag = 1;
	}
	if (!flag)
		return (ERROR);
	pre_sort(arr, 0, len - 1);
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
	return (OK);
}

static int reverse_chunck(int count_ra, int count_rb)
{
	while (count_ra-- > 0&& count_rb-- > 0)
		rr(ALL);
	while (count_ra-- > 0)
		rr(A);
	while (count_rb-- > 0)
		rr(B);
	return (OK);
}

int A_to_B(int len)
{
	int pivot[2];
	int count[3];

	if (len <= 1)
		return (OK);
	if (len == 2 && st()->n[A][head]->link[next]->data > \
					st()->n[A][head]->link[next]->link[next]->data)
		return (s(A));
	if (!get_pivot(A << 1, len, pivot))
		return (OK);
	ft_bzero(count, sizeof(int) * 3);
	while (len--)
		if (st()->n[A][head]->link[next]->data >= pivot[1])
			count[ra] += r(A);
		else
		{
			count[pb] += p(B);
			if (st()->n[B][head]->link[next]->data >= pivot[0])
				count[rb] += r(B);
		}
	return (reverse_chunck(count[ra], count[rb]) && \
			A_to_B(count[ra]) && B_to_A(count[rb]) && \
			B_to_A(count[pb] - count[rb]));
}

int B_to_A(int len)
{
	int pivot[2];
	int count[3];

	if (len == 2 && st()->n[B][head]->link[next]->data < \
					st()->n[B][head]->link[next]->link[next]->data)
		return (s(B) && p(A) && p(A));
	if (len == 0)
		return (OK);
	if (len == 1)
		return (p(A));
	if (!get_pivot(B << 1, len, pivot))
		return (OK);
	ft_bzero(count, sizeof(int) * 3);
	while (len--)
		if (st()->n[B][head]->link[next]->data < pivot[0])
			count[rb] += r(B);
		else
		{
			count[pa] += p(A);
			if (st()->n[A][head]->link[next]->data < pivot[1])
				count[ra] += r(A);
		}
	return (A_to_B(count[pa] - count[ra]) && \
			reverse_chunck(count[ra], count[rb]) && \
			A_to_B(count[ra]) && B_to_A(count[rb]));
}

