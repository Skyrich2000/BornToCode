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

// typedef struct s_world t_wold;
// camera 구조체
typedef struct s_camera
{
	t_pnt	pos;
	t_vec	dir;
	t_vec	hor;
	t_vec	ver;
	t_vec	low_left_corner;
	double			view_width;
	double			view_height;
	double			fov;
	// double lens_radius;
	t_vec	u;
	t_vec	v;
	t_vec	w;
	void 	*img;
	char	*img_addr;
	int		render_index;
	struct s_camera	*next;
} 				t_camera;

// image data 구조체
// typedef struct s_screen
// {
// 	void	*mlx;
// 	void	*win;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	double	wid;
// 	double	hei;
// 	int		anti;
// }		t_screen;

// the everything...
// typedef struct s_minirt
// {
// 	t_screen	scr;
// 	t_world		*wrd;
// 	t_camera	*cam;
// 	t_camera	*curr_cam;
// 	t_light		*light;
// }		t_minirt;

t_camera	*init_camera();
int			move_camera(t_camera *cam, t_vec lookfrom, t_vec dir, double fov);
int			add_camera(t_minirt *mini, t_vec lookfrom, t_vec dir, double fov);
void	draw(t_minirt *m);
typedef struct s_render_args
{
	t_minirt	*mini;
	int			h_start;
	int			w_start;
	int			h_end;
	int			w_end;
} t_render_args;


int	render(void *data);
int		render_thread(t_minirt *mini);

#endif
