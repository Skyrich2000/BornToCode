#ifndef LIBRARY_H
# define LIBRARY_H

# include "stdlib.h"

char		*sl_strjoin(char *s1, char *s2);
char		*sl_itoa(int n);
void		*sl_memcpy(void *dest, const void *src, size_t n);
void		sl_bzero(void *s, int n);
void		sl_free(void *data);

#endif
