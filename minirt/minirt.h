#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vector.h"
# include "object.h"
# include "library.h"
// camera 구조체
typedef struct s_camera
{
	t_vec	pos;
	t_vec	horizon;
	t_vec	vertical;
	t_vec	focal_length;
	t_vec	low_left_corner;
	double			view_width;
	double			view_height;
	double			ratio;
} 				t_camera;

// image data 구조체
typedef struct s_screen
{
	void	*mlx;
	void	*win;
	void 	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_screen;

void set_camera(t_camera *cam, t_vec pos, double height, double ratio);
int	render(t_screen *screen, t_world *world, t_camera *cam);

#endif
