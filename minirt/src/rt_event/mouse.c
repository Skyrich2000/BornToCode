#include "minirt.h"

int mouse_up(int button, int x,int y, void *param)
{
    int     diff_x;
    int     diff_y;
    t_vec   dir;

    if (button != 1)
        return (0);
    diff_x = x - m()->scr.mouse_x;
    diff_y = y - m()->scr.mouse_y;
    dir = m()->curr_cam->dir;
    dir = vec_add(dir, \
            vec_muln(vec_unit_(&m()->curr_cam->hor), diff_x / m()->scr.wid * 2));
    dir = vec_add(dir, \
            vec_muln(vec_unit_(&m()->curr_cam->ver), -diff_y / m()->scr.hei * 2));
    dir = vec_unit(dir);
    set_camera(m()->curr_cam, m()->curr_cam->pos, dir, m()->curr_cam->fov);
    draw(m());
    return (0);
}

int mouse_down(int button, int x,int y, void *param)
{
    if (button != 1)
        return (0);
    m()->scr.mouse_x = x;
    m()->scr.mouse_y = y;
    return (0);
}