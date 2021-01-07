/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:06:17 by ycha              #+#    #+#             */
/*   Updated: 2020/12/27 21:48:38 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	if (c == -1)
		return (-1);
	if (c > 255)
		return (c);
	if ('a' <= chr && chr <= 'z')
		return (chr + 'A' - 'a');
	return (chr);
}
