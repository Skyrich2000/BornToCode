#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vector.h"
# include "library.h"
# include "material.h"
# include "light.h"
# include "object.h"
# include "parse.h"
# include "event.h"

# define MAX_DEPTH 50
# define ERROR 0
# define OK 1
# define EPSILON 1e-6
# define LUMEN 3

typedef struct s_world t_world;
// camera 구조체
typedef struct s_camera
{
	t_pnt	pos;
	t_vec	horizon;
	t_vec	vertical;
	t_vec	low_left_corner;
	double			view_width;
	double			view_height;
	double			fov;

	double lens_radius;
	t_vec	u;
	t_vec	v;
	t_vec	w;
	struct s_camera	*next;
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

t_camera		*init_camera();
t_light		*init_light();
int		add_camera(t_camera *head, t_vec lookfrom, t_vec dir, double fov);
int	render(t_minirt *mini);
t_clr phong(t_world *world, t_hit_record *rec);
#endif
