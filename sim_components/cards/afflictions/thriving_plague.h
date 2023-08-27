#pragma once
#include "../affliction.h"

class thriving_plague : public affliction
{
public:
	double dmg_mult_per_afflicted_part;
	thriving_plague(sim_deck* deck, int deck_index);
};