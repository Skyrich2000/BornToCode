#include "engine.h"

void		scr_inverter_before(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	in_mv;
	int dir;
	int out_mv;
	int dis;
	t_instance *ins;

	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];

	scr_inverter_destroy_trigger(this, in_mv);

	dir = (in_mv & (0b00110)) | (out_mv & (0b00110));
	g()->global.player->signal = SIG_MV_AUTO | in_mv | scr_convert_mv_signal(dir);

	h_mv = (((in_mv & SIG_MV_RIGHT) > 0) - ((in_mv & SIG_MV_LEFT) > 0));
	v_mv = (((in_mv & SIG_MV_DOWN) > 0) - ((in_mv & SIG_MV_UP) > 0));
	dis = (this->x - g()->global.player->x) * h_mv + (this->y - g()->global.player->y) * v_mv - v_mv * 13;

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	ins = create_dummy_instance(this->x + h_mv * dis, this->y + v_mv * dis, !this->obj.inverter.inverted, -1);
	ins->signal = SIG_MV_AUTO | scr_reverse_mv_signal(out_mv) | scr_convert_mv_signal(dir);

	this->obj.inverter.dummy = ins;
}

void		scr_inverter_active(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	in_mv;
	int out_mv;
	int dir;

	printf("inversion start\n");
	g()->global.inverted = !this->obj.inverter.inverted;
	g()->global.invert_signal = SIG_ACTIVE;
	g()->global.player->signal = 0;


	scr_avatarize(PLAYER);
	g()->frame.skip_frame = 0;
	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];
	dir = this->signal & (SIG_DIR_LEFT | SIG_DIR_RIGHT);

	destroy_instance(this->obj.inverter.dummy);
	this->obj.inverter.dummy = 0;

	g()->global.player = create_player_instance(this->x, this->y);
	g()->global.player->signal = SIG_MV_AUTO | out_mv | dir;

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	create_trigger_instance((int [2]){this->x + h_mv * 96, this->y + v_mv * 90}, !this->obj.inverter.inverted, g()->global.player, 0);
}
