/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:49:26 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 18:02:08 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define A		0b000
# define B		0b010
# define ALL	0b100
# define PRINT	0b100

# define HEAD	0b000
# define TAIL	0b001

# define NEXT 0
# define PREV 1

# define OK 1
# define ERROR 0

typedef struct s_node
{
	int				data;
	struct s_node	*link[2];
}	t_node;

typedef struct s_list
{
	int				size[5];
	t_node			*n[5][2];
}	t_list;

typedef enum e_cmd
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	PP,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

int			input(int ac, char **av);

t_list		*st(void);
void		init_list(int pos);
int			swap(int pos);
int			push(int pos, int data);
int			pop(int pos, int *data);
int			top(int pos);
void		print_result(void);
void		free_list(t_node *node);

void		ft_swap(int *a, int *b);
void		ft_bzero(void *s, int n);
char		**ft_split(char *s, char c);
int			ft_atoi(char *str, int *data);
int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dest, const void *src, size_t n);

int			s(int stack);
int			p(int stack);
int			r(int stack);
int			rr(int stack);

void		sort_three(void);
void		sort_five(void);
int			a_to_b(int len);
int			b_to_a(int len);

#endif
