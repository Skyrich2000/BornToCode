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

void		scr_inverter_trigger(t_instance *this)
{
	int	h_mv;
	int v_mv;
	int sig;

	sig = SIG_MV_RIGHT;
	while (sig <= SIG_MV_DOWN)
	{
		if (this->obj.inverter.out_dir[sig])
		{
			h_mv = (((sig & SIG_MV_RIGHT) > 0) - ((sig & SIG_MV_LEFT) > 0));
			v_mv = (((sig & SIG_MV_DOWN) > 0) - ((sig & SIG_MV_UP) > 0));
			create_trigger_instance((int [2]){this->x + h_mv * 32, this->y + v_mv * 32}, g()->asset.spr_empty, this, SIG_BEFORE | sig);
		}
		sig = sig << 1;
	}
}

void		scr_inverter_before(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	mv;
	int out_mv;
	int dir;
	t_instance *ins;

	printf("before! \n");
	mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[mv];
	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));

	dir = scr_reverse_mv_signal(mv & (0b00110)) | (this->obj.inverter.out_dir[mv] & (0b00110));
	g()->global.player->signal = SIG_AUTO | scr_reverse_mv_signal(mv) | scr_convert_mv_signal(dir);

	ins = create_dummy_instance(this->x + h_mv * 48, this->y + v_mv * 48, !this->obj.inverter.inverted, 60);
	dir = (mv & (0b00110)) | (this->obj.inverter.out_dir[mv] & (0b00110));
	ins->signal = SIG_AUTO | scr_reverse_mv_signal(this->obj.inverter.out_dir[mv]) | scr_convert_mv_signal(dir);
	this->obj.inverter.dummy = ins;
}

void		scr_inverter_active(t_instance *this)
{
	int h_mv;
	int v_mv;
	int	mv;
	int out_mv;
	int dir;

	printf("inversion start\n");
	g()->global.inverted = S_INVERT;
	g()->global.state = S_INVERT;
	g()->global.total_time = g()->global.time;

	scr_avatarize(PLAYER);
	scr_avatarize(BOX);
	scr_avatarize(GOLD);


	destroy_instance(g()->instances[TRIGGER]->next->data); // TODO: fix this
	destroy_instance(this->obj.inverter.dummy);

	mv = scr_reverse_mv_signal(this->signal & 0b11110);
	out_mv = this->obj.inverter.out_dir[mv];
	printf("out mv %d\n", out_mv);
	h_mv = (((out_mv & SIG_MV_RIGHT) > 0) - ((out_mv & SIG_MV_LEFT) > 0));
	v_mv = (((out_mv & SIG_MV_DOWN) > 0) - ((out_mv & SIG_MV_UP) > 0));

	dir = (mv & (0b00110)) | (this->obj.inverter.out_dir[mv] & (0b00110));
	g()->global.player->signal = 0;
	g()->global.player = create_player_instance(this->x, this->y, !this->obj.inverter.inverted);
	g()->global.player->signal = SIG_AUTO | this->obj.inverter.out_dir[mv] | scr_convert_mv_signal(dir);
	create_trigger_instance((int [2]){this->x + h_mv * 96, this->y + v_mv * 96}, g()->asset.spr_empty, g()->global.player, 0);
}
