#include "engine.h"

int		keyboard_check(int keycode)
{
    return (g()->keys[keycode]);
}

int		key_press(int keycode)
{
    g()->keys[keycode] = 1;
	return (OK);
}

int		key_release(int keycode)
{
    g()->keys[keycode] = 0;
	return (OK);
}