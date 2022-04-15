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

# define MAX_GUI_OBJECT 100

typedef struct s_gui_object
{
	int			type;
	void		*obj;
	t_vec		pos;
}	t_gui_object;

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

	int				gui_object_top;
	t_gui_object	gui_object[MAX_GUI_OBJECT];
	t_gui_object	select_gui_object;
	struct s_camera	*next;
}	t_camera;

t_camera	*init_camera(void);
int			set_camera(t_camera *cam, t_vec lookfrom, t_vec dir, double fov);
int			add_camera(t_camera *head, t_vec lookfrom, t_vec dir, double fov);

void		render(void);
void		render_pixel(int x, int y);

void		set_gui(t_camera *cam);
void		draw_gui(void);

t_vec		*get_object_pos(void *obj, int type);
void		set_object_pos(void *obj, int type, t_vec pos);

t_vec		get_object_dir(void *obj, int type);
void		set_object_dir(void *obj, int type, t_vec start, t_vec diff);

#endif
