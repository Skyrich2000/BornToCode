#include "minirt.h"
#include "event.h"
#include <time.h>

static void	init_screen(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->width, screen->height, "Hellow World!");
	screen->ptr = mlx_new_image(screen->mlx, screen->width, screen->height); // 이미지 객체 생성
	screen->addr = mlx_get_data_addr(screen->ptr, &screen->bits_per_pixel, &screen->line_length, &screen->endian); // 이미지 주소 할당
}

static void	event(t_minirt *mini)
{
	mlx_key_hook(mini->scr.win, key_hook, &mini->scr); // esc close
	mlx_hook(mini->scr.win, 17, 0, exit_hook, 0); // x button close
}

static void draw(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->win, screen->ptr, 0, 0); // 생성한 이미지 객체 윈도우에 올리기
	mlx_loop(screen->mlx);
}

static double p2p(t_vec p1, t_vec p2)
{
	return (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2)));
}

static int	minirt(t_minirt *mini)
{
	clock_t start, end;		// time check

	// setting screen
	init_screen(&mini->scr);

	// setting event handler
	event(mini);

	// render first scene
	start = clock();		// time check
	render(mini);
	end = clock();		// time check
	printf("time : %f\n",(double)(end - start) / CLOCKS_PER_SEC);

	// draw screen to window
	draw(&mini->scr);
	return (0);
}

int		main()
{
	t_minirt	mini;

	//parsing(); //parsing 에러 체크

	// screen setting
	mini.scr.width = 1600; //  -> parse
	mini.scr.height = 900; //  -> parse
	mini.scr.anti = 100; // -> parse

	// material setting
	t_material material_ground = create_lambertian(vec(0.8, 0.8, 0.0));
	t_material material_center = create_lambertian(vec(0.1, 0.2, 0.5));
	t_material material_left = create_dielectric(1.5);
	t_material material_right = create_metal(vec(0.8, 0.6, 0.2), 0.0);

	// world setting
	mini.wrd = init_world();
	add_world(mini.wrd, create_sphere(vec( 0.0, -100.5, -1.0), 100), hit_sphere, &material_ground);
	add_world(mini.wrd, create_sphere(vec( 0.0, 0.0, -1.0), 0.5), hit_sphere, &material_center);
	add_world(mini.wrd, create_sphere(vec(-1.0, 0.0, -1.0), 0.5), hit_sphere, &material_left);
	add_world(mini.wrd, create_sphere(vec(-1.0, 0.0, -1.0), -0.45), hit_sphere, &material_left);
	add_world(mini.wrd, create_sphere(vec( 1.0, 0.0, -1.0), 0.5), hit_sphere, &material_right);

	// camera setting
	mini.cam = malloc(sizeof(t_camera) * 1); // -> parse needed

	t_vec lookfrom = vec(3, 3, 2);
	t_vec lookat = vec(0, 0, -1);
	t_vec vup = vec(0, 1, 0);
	double ratio = 16.0 / 9.0;
	double aperture = 2.0;
	double dist_to_focus = p2p(lookfrom, lookat);
	create_camera((&mini.cam[0]), lookfrom, lookat, vup, 20, ratio, aperture, dist_to_focus); // -> parse
	// create_camera((&mini.cam[0]), vec(-2, 2, 1), vec(0, 0, -1), vec(0, 1, 0), 20, (16.0 / 9.0)); // -> parse
	// start app
	minirt(&mini); //minirt 에러 체크
	return (0);
}
