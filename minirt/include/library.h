/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:34 by ycha              #+#    #+#             */
/*   Updated: 2021/04/11 19:17:00 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H
# include "minirt.h"

double rand_num(int anti, int min, int max);
double clamp(double n, double min, double max);
int trgb(int t, int r, int g, int b);
double ft_min(double a, double b);
double ft_abs(double n);
#endif
