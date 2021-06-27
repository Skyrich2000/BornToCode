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

#include "math.h"
#include "push_swap.h"

#define ra 0
#define rb 1
#define pb 2
#define pa 2

int			min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

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
	int		flag;
	t_node	*node;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (ERROR);
	i = 0;
	flag = 0;
	node = st()->n[pos >> 1][head]->link[next];
	while (node->link[next] && i < len)
	{
		arr[i] = node->data;
		node = node->link[next];
		if (i > 0)
		{
			if (((pos >> 1) == A) && arr[i - 1] > arr[i])
				flag = 1;
			if (((pos >> 1) == B) && arr[i - 1] < arr[i])
				flag = 1;
		}
		++i;
	}
	if (!flag)
	{
		// printf("나 정렬 되어있지롱~ %d : len %d", pos >> 1, len);
		// print_list("");
		free(arr);
		return (ERROR);
	}
	pre_sort(arr, 0, len - 1);
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
	return (OK);
}

static int	reverse_chunck(int count_ra, int count_rb)
{
	int	i;

	i = min(count_ra, count_rb);
	while (i--)
	// while (count_ra > 0 && count_rb > 0)
	{
		rr(ALL);
		// count_ra--;
		// count_rb--;
	}
	i = abs(count_ra - count_rb);
	while (i--)
	// while (count_ra > 0)
	{
		rr(count_ra < count_rb);
		// count_ra--;
	}
	// while (count_rb > 0)
	//{
	//	rr(B);
	//	count_rb--;
	//}
	return (OK);
}

int			A_to_B(int len)
{
	int	pivot[2];
	int	count[3];

	if (len <= 1)
		return (OK);
	if (len == 2)
	{
		if (st()->n[A][head]->link[next]->data >
			st()->n[A][head]->link[next]->link[next]->data)
		{
			s(A);
		}
		return (OK);
	}
	// print_list("A to B before");
	if (!get_pivot(A << 1, len, pivot))
		return (OK);
	ft_bzero(count, sizeof(int) * 3);
	while (len--)
	{
		if (st()->n[A][head]->link[next]->data >= pivot[1])
			r(A) && count[ra]++;
		else
		{
			p(B) && count[pb]++;
			if (st()->n[B][head]->link[next]->data >= pivot[0])
				r(B) && count[rb]++;
		}
	}
	// printf("[%d %d] ra %d rb %d pb %d | ", pivot[0], pivot[1], count[ra],
	// count[rb], count[pb]); print_list("A to B after");
	reverse_chunck(count[ra], count[rb]);
	// print_list("A to B last");
	A_to_B(count[ra]);
	B_to_A(count[rb]);
	B_to_A(count[pb] - count[rb]);
	return (OK);
	//return (reverse_chunck(count[ra], count[rb]) && \
			A_to_B(count[ra]) && B_to_A(count[rb]) && \
			B_to_A(count[pb] - count[rb]));
}

int			B_to_A(int len)
{
	int	pivot[2];
	int	count[3];

	if (len == 2)
	{
		if (st()->n[B][head]->link[next]->data <
			st()->n[B][head]->link[next]->link[next]->data)
		{
			s(B);
		}
		p(A);
		p(A);
		return (OK);
	}
	if (len == 1)
	{
		p(A);
		return (OK);
	}
	if (len == 0)
		return (OK);
	// print_list("B to A before");
	if (!get_pivot(B << 1, len, pivot))
	{
		while (len--)
			p(A);
		return (OK);
	}
	ft_bzero(count, sizeof(int) * 3);
	while (len--)
	{
		if (st()->n[B][head]->link[next]->data < pivot[0])
			r(B) && count[rb]++;
		else
		{
			p(A) && count[pa]++;
			if (st()->n[A][head]->link[next]->data < pivot[1])
				r(A) && count[ra]++;
		}
	}
	// printf("[%d %d] ra %d rb %d pa %d | ", pivot[0], pivot[1], count[ra],
	// count[rb], count[pa]); print_list("B to A after");
	A_to_B(count[pa] - count[ra]);
	reverse_chunck(count[ra], count[rb]);
	// print_list("B to A last");
	A_to_B(count[ra]);
	B_to_A(count[rb]);
	return (OK);
	//return (A_to_B(count[pa] - count[ra]) && \
			reverse_chunck(count[ra], count[rb]) && \
			A_to_B(count[ra]) && B_to_A(count[rb]));
}
