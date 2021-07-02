/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 08:24:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1 && *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	play_cmd(char *str)
{
	int	i;

	i = 12;
	while (i--)
	{
		if (i == 5)
			continue ;
		if (ft_strcmp((char [12][4]){"sa", "sb", "ss", "pa", "pb", "_", \
						"ra", "rb", "rr", "rra", "rrb", "rrr"}[i], str) == 0)
		{
			if (0 <= i && i < 3)
				s((i % 3) << 1);
			else if (3 <= i && i < 5)
				p((i % 3) << 1);
			else if (6 <= i && i < 9)
				r((i % 3) << 1);
			else if (9 <= i && i < 12)
				rr((i % 3) << 1);
			return (OK);
		}
	}
	return (ERROR);
}

static int	check_sort(void)
{
	t_node	*node;

	node = st()->n[A][HEAD]->link[NEXT]->link[NEXT];
	if (st()->size[B] != 0)
		return (ERROR);
	if (!node)
		return (OK);
	while (node && node->link[NEXT])
	{
		if (node->data < node->link[PREV]->data)
			return (ERROR);
		node = node->link[NEXT];
	}
	return (OK);
}

static int	input_cmd(void)
{
	char	*line;
	int		flag;
	int		result;

        flag = OK;
	while (1)
	{
		result = get_next_line(0, &line); // 그냥 엔터만 치면 리턴값이 머지
                if (result <= 0)
                        break;
		flag = play_cmd(line);
		free(line);
		if (!flag)
			return (ERROR);
	}
        if (*line != 0)
                flag = ERROR;
        free(line);
	return (flag);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (input(ac, av) && input_cmd())
	{
		if (check_sort())
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	free_list(st()->n[A][HEAD]);
	free_list(st()->n[B][HEAD]);
	free_list(st()->n[PRINT][HEAD]);
	return (0);
}
