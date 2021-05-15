#include "minirt.h"

int	parse_r(char **line, t_minirt *mini)
{
	if ((mini->scr.width && mini->scr.height) || \
		ft_arrsize(line) != 3 || \
		!ft_isnum(line[1]) || \
		!ft_isnum(line[2]))
		return (ERROR);
	mini->scr.width = ft_atoi(line[1]);
	mini->scr.height = ft_atoi(line[2]);
	return (OK);
}

int	parse_sp(char **line, t_minirt *mini)
{
	t_vec pos;
	t_vec color;
	double diameter;

	if (ft_arrsize(line) != 4 || \
		!ft_isnum(line[2]) || \
		!parse_split(&pos, line[1]) || \
		!parse_split(&color, line[3]))
		return (ERROR);
	diameter = ft_atod(line[2]);
	color = vec_divn(color, 255);
	return (add_world(mini->wrd, \
			create_sphere(pos, diameter), hit_sphere, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}

int	parse_sq(char **line, t_minirt *mini)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 5 || !ft_isnum(line[3]))
		return (ERROR);
	parsed.sq.sidesize = ft_atod(line[3]);
	return (parse_split(&(parsed.sq.pos), line[1]) && \
			parse_split(&(parsed.sq.n), line[2]) && \
			parse_split(&(parsed.sq.color), line[4]) && \
			parsed_list_add(box, sq, parsed));
}

// int	parse_tr(char **line, t_minirt *mini)
// {
// 	t_parsed	parsed;

// 	if (ft_arrsize(line) != 5)
// 		return (ERROR);
// 	return (parse_split(&(parsed.tr.po1), line[1]) && \
// 			parse_split(&(parsed.tr.po2), line[2]) && \
// 			parse_split(&(parsed.tr.po3), line[3]) && \
// 			parse_split(&(parsed.tr.color), line[4]) && \
// 			parsed_list_add(box, tr, parsed));
// }
