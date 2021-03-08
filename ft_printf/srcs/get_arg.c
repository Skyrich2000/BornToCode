/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:43:19 by ycha              #+#    #+#             */
/*   Updated: 2021/03/07 07:34:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "build.h"
#include <stdlib.h>
#include <stdio.h>

void *get_int(int length, va_list ap) {
        void *ret;

		if (!(ret = malloc(sizeof(long long int))))
			return (0);
		ft_bzero(ret, sizeof(long long int));
        if (length == 0)
                *(int *)ret = va_arg(ap, int);
        else if (length == 1)
                *(long long int *)ret = va_arg(ap, long long int);
        else if (length == 2)
                *(signed char *)ret = va_arg(ap, int); // signed char);
        else if (length == 3)
                *(long int *)ret = va_arg(ap, long int);
        else
                *(short int *)ret = va_arg(ap, int); //short int);
		return (ret);
}

void *get_unsigned_int(int length, va_list ap) {
        void *ret;

		if (!(ret = malloc(sizeof(unsigned long long int))))
			return (0);
		ft_bzero(ret, sizeof(unsigned long long int));
        if (length == 0)
                *(unsigned int *)ret = va_arg(ap, unsigned int);
        else if (length == 1)
                *(unsigned long long int *)ret = va_arg(ap, unsigned long long int);
        else if (length == 2)
                *(unsigned char *)ret = va_arg(ap, int ); //unsigned char);
        else if (length == 3)
                *(unsigned long int *)ret = va_arg(ap, unsigned long int);
        else if (length == 4)
                *(unsigned short int *)ret = va_arg(ap, int ); //unsigned short int);
		return (ret);
}

void *get_pointer(int length, va_list ap) {
	void *ret;

	if (!(ret = malloc(sizeof(void *))))
		return (0);
	ft_bzero(ret, sizeof(void *));
	*(void **)ret = va_arg(ap, void *);
	return (ret);
}
