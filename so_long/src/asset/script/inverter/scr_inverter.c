#include "engine.h"

int			scr_reverse_mv_signal(int signal)
{
	return ((signal & 0b10100) >> 1 | (signal & 0b1010) << 1);
}

int			scr_convert_mv_signal(int signal)
{
	if (signal & (SIG_MV_RIGHT | SIG_MV_LEFT))
		return (signal << 4);
	return (signal << 2);
}

void		scr_inverter_create_trigger(t_instance *this)
{
	int	h_mv;
	int v_mv;
	int mv;
	int reverse_mv;

	mv = SIG_MV_RIGHT;
	while (mv <= SIG_MV_DOWN)
	{
		if (this->obj.inverter.out_dir[mv])
		{
			reverse_mv = scr_reverse_mv_signal(mv);
			h_mv = (((reverse_mv & SIG_MV_RIGHT) > 0) - ((reverse_mv & SIG_MV_LEFT) > 0));
			v_mv = (((reverse_mv & SIG_MV_DOWN) > 0) - ((reverse_mv & SIG_MV_UP) > 0));
			this->obj.inverter.triggers[mv] = create_trigger_instance((int [2]){this->x + h_mv * 32, this->y + v_mv * 32}, this->obj.inverter.inverted, this, SIG_BEFORE | mv);
		}
		mv = mv << 1;
	}
}

void		scr_inverter_destroy_trigger(t_instance *this, int exclusive_signal)
{
	int mv;

	mv = SIG_MV_RIGHT;
	while (mv <= SIG_MV_DOWN)
	{
		if (mv != exclusive_signal && this->obj.inverter.out_dir[mv])
		{
			destroy_instance(this->obj.inverter.triggers[mv]);
		}
		mv = mv << 1;
	}
}


void		scr_inverter_before(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	in_mv;
	int out_mv;
	int dir;
	t_instance *ins;

	printf("before! \n");
	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];

	// TODO: if dir is 0
	dir = (in_mv & (0b00110)) | (out_mv & (0b00110));
	g()->global.player->signal = SIG_AUTO | in_mv | scr_convert_mv_signal(dir);

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	ins = create_dummy_instance(this->x + h_mv * 48, this->y + v_mv * 48, !this->obj.inverter.inverted, -1);
	ins->signal = SIG_AUTO | scr_reverse_mv_signal(out_mv) | scr_convert_mv_signal(dir);

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
	g()->global.invert_signal = 1;
	g()->global.player->signal = 0;

	scr_avatarize(PLAYER);

	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];
	dir = this->signal & (SIG_DIR_LEFT | SIG_DIR_RIGHT);

	scr_inverter_destroy_trigger(this, in_mv);
	destroy_instance(this->obj.inverter.dummy);

	g()->global.player = create_player_instance(this->x, this->y, !this->obj.inverter.inverted);
	g()->global.player->signal = SIG_AUTO | out_mv | dir;

	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));
	create_trigger_instance((int [2]){this->x + h_mv * 96, this->y + v_mv * 96}, !this->obj.inverter.inverted, g()->global.player, 0);
}
