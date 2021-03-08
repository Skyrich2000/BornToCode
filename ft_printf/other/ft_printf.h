/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:59:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/09 13:30:56 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flag
{
	int		left;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	padding;
}				t_flag;

char			*ft_join_precision(t_flag *flag, char *src);
char			*ft_join_width(t_flag *flag, char *src);
int				ft_parse(const char **fmt, t_flag *flag, va_list ap);
void			ft_parse_zero_minus(const char **fmt, t_flag *flag);
void			ft_parse_width(const char **fmt, va_list ap, t_flag *flag);
void			ft_parse_precision(const char **fmt, va_list ap, t_flag *flag);
int				ft_printf(const char *fmt, ...);
void			ft_init(t_flag *t);
int				ft_atoi_double(const char **nptr);
int				get_len_base(long long n, int base);
char			*ft_uitoa_base(unsigned int n, char *base);
char			*ft_ultoa_base(unsigned long n, char *base);
int				ft_type_num(va_list ap, t_flag *flag, char type);
int				ft_type_char(va_list ap, t_flag *flag, char type);
int				ft_type_address(va_list ap, t_flag *flag);
int				ft_type_str(va_list ap, t_flag *flag);

#endif
