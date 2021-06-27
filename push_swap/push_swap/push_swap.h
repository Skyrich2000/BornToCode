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

# include <stdio.h>
# include <stdlib.h>

# define A 0
# define B 1
# define ALL 2

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

t_list		*st();
void		init_list();
int			swap(int pos);
int			push(int pos, int data);
int			pop(int pos, int *data);
int			top(int pos);
void		print_list(char *prefix);
void		free_list();

int			ft_atoi(char *str, int *data);
void		ft_bzero(void *s, size_t n);
void		ft_swap(int *a, int *b);
char		**ft_split(char const *s, char c);

int			s(int stack);
int			p(int stack);
int			r(int stack);
int			rr(int stack);

void		sort_three();
void		sort_five();
int			A_to_B(int len);
int			B_to_A(int len);

#endif
