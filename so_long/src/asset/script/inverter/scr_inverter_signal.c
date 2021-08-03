#include "engine.h"

void		scr_inverter_wait(t_instance *this)
{
	int	in_mv;
	int out_mv;
	int dir;

	printf("wait! \n");
	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];

	dir = (in_mv & (0b00110)) | (out_mv & (0b00110));

	g()->global.player->signal = SIG_MV_AUTO | scr_convert_mv_signal(dir);
}

void		scr_inverter_before(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	in_mv;
	int out_mv;
	int dir;
	t_instance *ins;

	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];

	scr_inverter_destroy_trigger(this, in_mv);

	dir = (in_mv & (0b00110)) | (out_mv & (0b00110));
	g()->global.player->signal = SIG_MV_AUTO | in_mv | scr_convert_mv_signal(dir);

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	ins = create_dummy_instance(this->x + h_mv * 48, this->y + v_mv * 48, !this->obj.inverter.inverted, -1);
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

	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];
	dir = this->signal & (SIG_DIR_LEFT | SIG_DIR_RIGHT);

	destroy_instance(this->obj.inverter.dummy);

	g()->global.player = create_player_instance(this->x, this->y, !this->obj.inverter.inverted);
	g()->global.player->signal = SIG_MV_AUTO | out_mv | dir;

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	create_trigger_instance((int [2]){this->x + h_mv * 96, this->y + v_mv * 90}, !this->obj.inverter.inverted, g()->global.player, 0);
}
