/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:01:53 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 17:46:50 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_unique(int num)
{
	t_node	*node;

	node = st()->n[A][HEAD]->link[NEXT];
	while (node->link[NEXT])
	{
		if (node->data == num)
			return (ERROR);
		node = node->link[NEXT];
	}
	return (OK);
}

static int	is_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (ERROR);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (ERROR);
		str++;
	}
	return (OK);
}

static int	input_sub(char *str)
{
	int		j;
	int		data;
	char	**sp;
	char	**s;

	sp = ft_split(str, ' ');
	j = 0;
	s = sp;
	while (s && *s++)
		j++;
	if (j == 0)
		return (ERROR);
	while (j--)
	{
		if (!(is_num(sp[j]) && ft_atoi(sp[j], &data) && is_unique(data)))
			return (ERROR);
		push(A | HEAD, data);
	}
	s = sp;
	while (*s)
		free(*s++);
	free(sp);
	return (OK);
}

int			input(int ac, char **av)
{
	int	i;

	init_list(A);
	init_list(B);
	init_list(PRINT);
	i = ac;
	while (--i > 0)
		if (!input_sub(av[i]))
			return (ERROR);
	return (OK);
}
