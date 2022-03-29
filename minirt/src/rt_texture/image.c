#include "minirt.h"

t_clr		image_value(t_texture *this, double u, double v)
{
    int 	    color;
    t_vec       ret;
    const int	u2 = floor(u * this->width);
	const int	v2 = floor((1 - v) * this->height);

    color = *(int *)(this->addr + \
		(v2 * this->line_length + u2 * (this->bits_per_pixel / 8)));
    ret = vec(color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
    return (vec_divn(ret, 255));
}