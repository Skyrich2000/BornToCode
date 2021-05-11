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
	double	fov;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[3]))
		return (ERROR);
	fov = ft_atod(line[3]);
	parse_split(&lookfrom, line[1]);
	parse_split(&dir, line[2]);
	return (add_camera(mini->cam, lookfrom, dir, fov));
}

int parse_l(char **line, t_minirt *mini)
{
	t_pnt	origin;
	t_clr	color;
	double	ratio;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	ratio = ft_atod(line[2]);
	parse_split(&origin, line[1]);
	parse_split(&color, line[3]);
	color = vec_divn(color, 255);
	return (add_light(mini->wrd->light, origin, color, ratio));
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

// int parse_pl(char **line, t_minirt *mini)
// {
// 	t_parsed	parsed;

// 	if (ft_arrsize(line) != 4)
// 		return (ERROR);
// 	return (parse_split(&(parsed.pl.pos), line[1]) && \
// 			parse_split(&(parsed.pl.n), line[2]) && \
// 			parse_split(&(parsed.pl.color), line[3]) && \
// 			parsed_list_add(box, pl, parsed));
// }
