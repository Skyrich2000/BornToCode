/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:37:05 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/27 20:01:20 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*p;

	cnt = 0;
	p = lst;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	return (cnt);
}
