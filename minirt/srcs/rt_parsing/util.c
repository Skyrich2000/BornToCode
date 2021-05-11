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
	if (ft_arrsize(tmp) != 3 ||!ft_isnum(tmp[0]) || !ft_isnum(tmp[1]) || !ft_isnum(tmp[2]))
		return (ERROR);
	input->x = ft_atod(tmp[0]);
	input->y = ft_atod(tmp[1]);
	input->z = ft_atod(tmp[2]);
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
