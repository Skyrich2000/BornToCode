#include "minirt.h"

static int	transfrom_3d_to_2d(t_camera *cam, t_vec *pos_3d, t_vec *pos_2d)
{
	const t_vec	R[3] = {
		{cam->u.x, cam->v.x, cam->dir.x},
		{cam->u.y, cam->v.y, cam->dir.y},
		{cam->u.z, cam->v.z, cam->dir.z},
	};
	const t_vec	R_t[3] = {
		{R[0].x, R[1].x, R[2].x},
		{R[0].y, R[1].y, R[2].y},
		{R[0].z, R[1].z, R[2].z},
	};
	const t_vec	pos_on_screen = {
		vec_dot_((t_vec *)&R_t[0], pos_3d),
		vec_dot_((t_vec *)&R_t[1], pos_3d),
		vec_dot_((t_vec *)&R_t[2], pos_3d),
	};
	double		x;
	double		y;

	x = pos_on_screen.x / cam->view_width * m()->scr.wid;
	y = m()->scr.hei - pos_on_screen.y / cam->view_height * m()->scr.hei;
	if (x < 0 || x > m()->scr.wid || y < 0 || y > m()->scr.hei)
		return (ERROR);
	*pos_2d = vec(x, y, 0);
	return (OK);
}

static int	get_screen_pos(t_camera *cam, t_vec world_pos, t_vec *screen_pos)
{
	double		t;
	t_ray		ray;
	t_vec		pos_on_cam;

	ray.origin = world_pos;
	ray.dir = vec_sub_(&cam->pos, &world_pos);
	if (!_get_plane_t((t_vec *[2]){&cam->low_left_corner, &cam->dir}, &ray, \
						(double [2]){0.001, 1.0}, &t))
		return (ERROR);
	if (t >= 1.0)
		return (ERROR);
	pos_on_cam = vec_sub(ray_at(&ray, t), cam->low_left_corner);
	if (!transfrom_3d_to_2d(cam, &pos_on_cam, screen_pos))
		return (ERROR);
	return (OK);
}

void	addX(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.x += 1;
		((t_triangle *)select_gui_object->obj)->p2.x += 1;
		((t_triangle *)select_gui_object->obj)->p3.x += 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.x += 1;
}

void	subX(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.x -= 1;
		((t_triangle *)select_gui_object->obj)->p2.x -= 1;
		((t_triangle *)select_gui_object->obj)->p3.x -= 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.x -= 1;
}

void	addY(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.y += 1;
		((t_triangle *)select_gui_object->obj)->p2.y += 1;
		((t_triangle *)select_gui_object->obj)->p3.y += 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.y += 1;
}

void	subY(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.y -= 1;
		((t_triangle *)select_gui_object->obj)->p2.y -= 1;
		((t_triangle *)select_gui_object->obj)->p3.y -= 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.y -= 1;
}

void	addZ(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.z += 1;
		((t_triangle *)select_gui_object->obj)->p2.z += 1;
		((t_triangle *)select_gui_object->obj)->p3.z += 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.z += 1;
}

void	subZ(t_gui_object *select_gui_object)
{
	if (select_gui_object->type == TRIANGLE)
	{
		((t_triangle *)select_gui_object->obj)->p1.z -= 1;
		((t_triangle *)select_gui_object->obj)->p2.z -= 1;
		((t_triangle *)select_gui_object->obj)->p3.z -= 1;
		return ;
	}
	((t_sphere *)select_gui_object->obj)->c.z -= 1;
}

void	set_gui_button(t_camera *cam, t_object *obj)
{
	if (!obj)
		return ;
	cam->gui_button_top = 0;
	cam->gui_button[cam->gui_button_top].text = "X + 1";
	cam->gui_button[cam->gui_button_top].f = addX;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(1, 0, 0));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
	cam->gui_button[cam->gui_button_top].text = "X - 1";
	cam->gui_button[cam->gui_button_top].f = subX;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(-1, 0, 0));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
	cam->gui_button[cam->gui_button_top].text = "Y + 1";
	cam->gui_button[cam->gui_button_top].f = addY;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(0, 1, 0));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
	cam->gui_button[cam->gui_button_top].text = "Y - 1";
	cam->gui_button[cam->gui_button_top].f = subY;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(0, -1, 0));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
	cam->gui_button[cam->gui_button_top].text = "Z + 1";
	cam->gui_button[cam->gui_button_top].f = addZ;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(0, 0, 1));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
	cam->gui_button[cam->gui_button_top].text = "Z - 1";
	cam->gui_button[cam->gui_button_top].f = subZ;
	cam->gui_button[cam->gui_button_top].world_pos = vec_add(obj->sphere.c, vec(0, 0, -1));
	get_screen_pos(cam, cam->gui_button[cam->gui_button_top].world_pos, &cam->gui_button[cam->gui_button_top].pos);
	cam->gui_button_top++;
}

void	set_gui_objects(t_camera *cam)
{
	int			i;
	t_world		*w;

	if (cam->select_gui_object.obj)
	{
		i = -1;
		get_screen_pos(cam, ((t_object *)cam->select_gui_object.obj)->sphere.c, \
							&cam->select_gui_object.pos);
		while (++i < cam->gui_button_top)
		{
			get_screen_pos(cam, cam->gui_button[i].world_pos, &cam->gui_button[i].pos);
		}
	}
	cam->gui_object_top = 0;
	w = m()->wrd->next;
	while (w && w->next && cam->gui_object_top < MAX_GUI_OBJECT)
	{
		if (get_screen_pos(cam, w->obj.sphere.c, \
							&cam->gui_object[cam->gui_object_top].pos))
		{
			cam->gui_object[cam->gui_object_top].type = w->type;
			cam->gui_object[cam->gui_object_top].obj = &w->obj;
			cam->gui_object_top++;
		}
		w = w->next;
	}
	return ;
}
