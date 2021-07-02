/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 18:02:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (input(ac, av))
	{
		if (st()->size[A] == 3)
			sort_three();
		else if (st()->size[A] == 5)
			sort_five();
		else
			a_to_b(st()->size[A]);
		print_result();
	}
	else
		write(2, "Error\n", 6);
	free_list(st()->n[A][HEAD]);
	free_list(st()->n[B][HEAD]);
	free_list(st()->n[PRINT][HEAD]);
	return (0);
}
