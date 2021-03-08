/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:10:46 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/27 20:39:39 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	now = *lst;
	while (now)
	{
		tmp = now->next;
		ft_lstdelone(now, del);
		now = tmp;
	}
	*lst = 0;
}
