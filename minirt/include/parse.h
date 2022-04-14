/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:50 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:51:50 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "minirt.h"
# define WHITESPACE "\t\n\v\f\r "
# define MAX_FILE_READ 4400000

typedef struct s_minirt	t_minirt;

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

int	parse_pl_metal(char **line);
int	parse_sp_metal(char **line);
int	parse_sq_metal(char **line);
int	parse_cy_metal(char **line);
int	parse_tr_metal(char **line);

int	parse_pl_dielectric(char **line);
int	parse_sp_dielectric(char **line);
int	parse_sq_dielectric(char **line);
int	parse_cy_dielectric(char **line);
int	parse_tr_dielectric(char **line);

int	parse_pl_lambertian(char **line);
int	parse_sp_lambertian(char **line);
int	parse_sq_lambertian(char **line);
int	parse_cy_lambertian(char **line);
int	parse_tr_lambertian(char **line);

#endif
