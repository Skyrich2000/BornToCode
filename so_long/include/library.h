#ifndef LIBRARY_H
# define LIBRARY_H

# include "stdlib.h"

int			sl_strlen(char *s);
char		*sl_strjoin(char *s1, char *s2);
char		*sl_itoa(int n);
void		*sl_memcpy(void *dest, const void *src, size_t n);
void		sl_bzero(void *s, int n);
void		sl_free(void *data);
char		**sl_free_split(char **s);
char		**sl_split(char *s, char c);
int			sl_rev_atoi(char *str);
int			sl_check_size(char *s, char c);

#endif
