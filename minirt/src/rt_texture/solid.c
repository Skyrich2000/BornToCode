#include "minirt.h"

t_clr		solid_value(t_texture *this, double u, double v)
{
    (void)u;
    (void)v;
    return (this->color);
}