#include "minirt.h"

// int parse_a(char **line, t_minirt *mini)
// {
// 	t_parsed	parsed;

// 	if (ft_arrsize(line) != 3 || !ft_isnum(line[1]))
// 		return (ERROR);
// 	parsed.a.val = ft_atod(line[1]);
// 	return (parse_split(&(parsed.a.color), line[2]) && \
// 			parsed_list_add(box, a, parsed));
// }

int		parse_c(char **line, t_minirt *mini)
{
	t_vec	lookfrom;
	t_vec	dir;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[3]))
		return (ERROR);
	return (parse_split(&lookfrom, line[1]) && \
			parse_split(&dir, line[2]) && \
			add_camera(mini->cam, lookfrom, dir, ft_atod(line[3])));
}

int parse_l(char **line, t_minirt *mini)
{
	t_pnt	origin;
	t_clr	color;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	return (parse_split(&origin, line[1]) && \
			parse_split(&color, line[3]) && \
			add_light(mini->wrd->light, origin, vec_divn(color, 255), ft_atod(line[2])));
}

int parse_pl(char **line, t_minirt *mini)
{
	t_pnt origin;
	t_vec n;
	t_clr color;

	if (ft_arrsize(line) != 4 || \
		!parse_split(&origin, line[1]) || \
		!parse_split(&n, line[2]) || \
		!parse_split(&color, line[3]))
			return (ERROR);
	color = vec_divn(color, 255);
	return (add_world(mini->wrd, create_plane(origin, n, color), \
			hit_plane, create_metal(color, (double)rand() / (double)RAND_MAX), color));

}

// int parse_cy(char **line, t_minirt *mini)
// {
// 	t_parsed	parsed;

// 	if (ft_arrsize(line) != 6 || !ft_isnum(line[3]) || !ft_isnum(line[4]))
// 		return (ERROR);
// 	parsed.cy.diameter = ft_atod(line[3]);
// 	parsed.cy.hei = ft_atod(line[4]);
// 	return (parse_split(&(parsed.cy.pos), line[1]) && \
// 			parse_split(&(parsed.cy.n), line[2]) && \
// 			parse_split(&(parsed.cy.color), line[5]) && \
// 			parsed_list_add(box, cy, parsed));
// }


