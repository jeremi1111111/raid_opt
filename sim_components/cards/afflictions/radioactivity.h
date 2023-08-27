#pragma once
#include "../affliction.h"

class radioactivity : public affliction
{
public:
	double dmg_mult_per_second;
	radioactivity(sim_deck* deck, int deck_index);
};
