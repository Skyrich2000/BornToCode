#ifndef TEXTURE_H
# define TEXTURE_H
# include <stdio.h>
# include "minirt.h"

# define TEXTURE_SOLID			0
# define TEXTURE_CHECKERBOARD	1
# define TEXTURE_IMAGE			2
# define TEXTURE_MIRROR			3

typedef struct s_texture
{
	int		type;
	t_clr	color;
	void	*image;
	void	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_clr	(*value)(struct s_texture *this, double u, double v);
}	t_texture;

t_texture	create_texture(t_clr color, char *name);

t_clr		solid_value(struct s_texture *this, double u, double v);
t_clr		checkboard_value(struct s_texture *this, double u, double v);
t_clr		image_value(struct s_texture *this, double u, double v);

#endif
