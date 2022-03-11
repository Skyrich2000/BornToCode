#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "minirt.h"
# define WHITESPACE "\t\n\v\f\r "
# define MAX_FILE_READ 4400000

typedef struct s_minirt	t_minirt;

typedef enum e_parsable
{
	r = 0,
	a,
	c,
	l,
	sp,
	pl,
	sq,
	cy,
	tr
}	t_parsable;

int	printf_error(void);
int	input(int argc, char **argv);
int	parse_split(t_vec *input, char *line);

int	parse_r(char **line);
int	parse_a(char **line);
int	parse_c(char **line);
int	parse_l(char **line);
int	parse_pl(char **line);
int	parse_sp(char **line);
int	parse_sq(char **line);
int	parse_cy(char **line);
int	parse_tr(char **line);

#endif
