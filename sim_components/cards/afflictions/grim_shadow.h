#pragma once
#include "../affliction.h"

class grim_shadow : public affliction
{
public:
	double dmg_mult_per_stack;
	grim_shadow(sim_deck* deck, int deck_index);
};