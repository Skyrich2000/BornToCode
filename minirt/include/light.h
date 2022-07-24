/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:52:01 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:52:02 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"

# define LUMEN 3
# define KSN	28
# define KS		0.4

typedef struct s_minirt	t_minirt;

typedef struct s_light
{
	t_pnt			origin;
	t_clr			color;
	double			ratio;
	struct s_light	*next;
}	t_light;

t_light	*init_light(void);
int		add_light(t_light *head, t_pnt origin, t_clr color, double ratio);

t_clr	phong(t_hit_record *rec);

#endif
