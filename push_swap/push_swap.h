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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
# define A 0
# define B 2
# define head 0
# define tail 1
# define next 0
# define prev 1
# define OK 1
# define ERROR 0

typedef struct		s_node
{
	int				data;
	struct s_node	*link[2];
}					t_node;

typedef struct		s_list
{
	int				size[2];
	t_node			*n[2][2];

}					t_list;

typedef enum		e_cmd
{
	sa = 0, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
}					t_cmd;

t_list		*st();
void		init_list();
int			swap(int pos);
int			push(int pos, int data);
int			pop(int pos, int *data);
void		print_list(char *prefix);
void		free_list();

void		c(t_cmd cmd);
void		sort();

#endif
