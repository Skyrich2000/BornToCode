#include "minirt.h"

int	printf_error(void)
{
	printf("parsing error\n");
	return (ERROR);
}

int parse_split(t_vec *input, char *line)
{
	char **tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3 || \
		!ft_atod(&input->x, tmp[0]) || \
		!ft_atod(&input->y, tmp[1]) || \
		!ft_atod(&input->z, tmp[2]))
		return (ERROR);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

// int parsed_list_add(t_minirt *mini, t_parsable index, t_parsed parsed)
// {
// 	t_parsed_list *t;

// 	t = malloc(sizeof(t_parsed_list));
// 	if (!t)
// 		return (ERROR);
// 	t->id = parsed;
// 	t->next = box->parsed[index].next;
// 	box->parsed[index].next = t;
// 	return (OK);
// }
