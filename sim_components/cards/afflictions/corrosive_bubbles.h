#pragma once
#include "../affliction.h"

class corrosive_bubbles : public affliction
{
public:
	double outburst_dmg_mult;
	corrosive_bubbles(sim_deck* deck, int deck_index);
};