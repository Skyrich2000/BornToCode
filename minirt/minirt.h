#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <time.h>

// vector 구조체
typedef struct s_vec
{
	double x;
	double y;
	double z;
}		t_vec;

typedef struct s_ray
{
	t_vec origin;
	t_vec dir;
}	t_ray;

// mlx 구조체
typedef struct	s_window
{
	void		*mlx;
	void		*win;
}				t_window;

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
	void 	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_screen;


/*
** ray member function
*/
void ray_at(t_vec *out, t_ray *ray, double t);

/*
** vector member function
*/
void vec(t_vec *out, double x, double y, double z);
void vec_cal(t_vec *out, t_vec *v, double *a, int n);
void vec_cross(t_vec *out, t_vec *v1, t_vec *v2);
void vec_unit(t_vec *out, t_vec *vec);
double vec_dot(t_vec *v1, t_vec *v2);

void vec_print(t_vec *vec);

int exit_hook();
int	key_hook(int keycode, t_window *vars);
