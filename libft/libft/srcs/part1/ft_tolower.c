/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:08:04 by ycha              #+#    #+#             */
/*   Updated: 2020/12/27 21:50:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	if (c == -1)
		return (-1);
	if (c > 255)
		return (c);
	if ('A' <= chr && chr <= 'Z')
		return (chr + 'a' - 'A');
	return (chr);
}
