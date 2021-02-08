/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:09:46 by ycha              #+#    #+#             */
/*   Updated: 2020/12/23 20:29:02 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		temp_n;
	const char	*temp;
	const char	*ptr;

	if (!*little)
		return ((char *)big);
	while (*big && n)
	{
		temp_n = n;
		temp = big;
		ptr = little;
		while (*ptr && temp_n)
		{
			if (*temp != *ptr)
				break ;
			++temp;
			++ptr;
			--temp_n;
		}
		if (*ptr == 0)
			return ((char *)big);
		++big;
		--n;
	}
	return (0);
}
