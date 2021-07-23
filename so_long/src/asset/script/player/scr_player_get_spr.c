#include "engine.h"
#include "asset.h"

t_sprite *scr_player_get_spr(int type, int inverted, int dir)
{
	int			idx;
	void		*asset;
	t_sprite	*spr;

	idx = 2 + (inverted == S_STRAIGHT) * 10 + type * 2 + (dir != 1);
	asset = &(g()->asset);
	spr = *(t_sprite **)(asset + sizeof(void *) * idx);
	return (spr);
}
