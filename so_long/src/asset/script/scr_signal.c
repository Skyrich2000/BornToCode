#include "engine.h"

int	scr_reverse_mv_signal(int signal)
{
	return ((signal & 0b10100) >> 1 | (signal & 0b1010) << 1);
}

int	scr_convert_mv_signal(int signal)
{
	if (signal & (SIG_MV_RIGHT | SIG_MV_LEFT))
		return (signal << 4);
	return (signal << 2);
}
