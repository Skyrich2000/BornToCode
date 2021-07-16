#include "engine.h"

int	sl_footprint_cmp(t_footprint *fp, t_footprint *prev_fp)
{
	if (fp->x == prev_fp->x && \
		fp->y == prev_fp->y && \
		fp->dir == prev_fp->dir)
		return (1);
	return (0);
}
