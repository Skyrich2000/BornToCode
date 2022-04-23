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

#ifndef CAMERA_H
# define CAMERA_H
# include "minirt.h"

typedef struct s_camera
{
	t_pnt			pos;
	t_vec			dir;
	t_vec			hor;
	t_vec			ver;
	t_vec			low_left_corner;
	double			view_width;
	double			view_height;
	double			fov;
	t_vec			u;
	t_vec			v;
	t_vec			w;
	void			*img;
	char			*img_addr;
	int				render_index;
	struct s_camera	*next;
}	t_camera;

t_camera	*init_camera(void);
int			set_camera(t_camera *cam, t_vec lookfrom, t_vec dir, double fov);
int			add_camera(t_camera *head, t_vec lookfrom, t_vec dir, double fov);

void		draw(void);
void		render_pixel(int i, int j);

#endif
