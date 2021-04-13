#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vector.h"
# include "object.h"
# include "library.h"

# define MAX_DEPTH 50

// camera 구조체
typedef struct s_camera
{
	t_vec	pos;
	t_vec	horizon;
	t_vec	vertical;
	t_vec	low_left_corner;
	double			view_width;
	double			view_height;
	double			ratio;

	double lens_radius;
	t_vec	u;
	t_vec	v;
	t_vec	w;
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
	int		anti;
}		t_screen;

// the everything...
typedef struct s_minirt
{
	t_screen	scr;
	t_world		*wrd;
	t_camera	*cam;
	t_camera	*curr_cam;
}		t_minirt;


void	create_camera(t_camera *cam, t_vec lookfrom, t_vec lookat, t_vec vup, double vfov, double ratio, double aperture, double dist_to_focus);
int	render(t_minirt *mini);

#endif
