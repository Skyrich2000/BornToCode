/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:30 by ycha              #+#    #+#             */
/*   Updated: 2021/06/15 14:24:30 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# include "vector.h"
# include "library.h"
# include "texture.h"
# include "material.h"
# include "light.h"
# include "object.h"
# include "parse.h"
# include "event.h"
# include "camera.h"

# define H_THREAD 4
# define W_THREAD 4

# define ANTI_ALIASING 0

# define MAX_DEPTH 50
# define ERROR 0
# define OK 1
# define EPSILON 1e-6

// image data 구조체
typedef struct s_screen
{
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	wid;
	double	hei;
	int		anti;
}		t_screen;

// the everything...
typedef struct s_minirt
{
	t_screen	scr;
	t_world		*wrd;
	t_camera	*cam;
	t_camera	*curr_cam;
	t_light		*light;
	int			num_a;
	int			num_c;
	int			num_l;
}		t_minirt;

t_minirt	*m(void);

#endif
