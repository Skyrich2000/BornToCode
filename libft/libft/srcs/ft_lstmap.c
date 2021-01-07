/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:19:06 by ycha              #+#    #+#             */
/*   Updated: 2021/01/07 12:09:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_list;

	new_list = 0;
	while(lst)
	{
		node = ft_lstnew(f(lst->content));
		ft_lstadd_front(&new_list, node);
	}
	ft_lstclear(&lst, del);
	return (new_list);
}
