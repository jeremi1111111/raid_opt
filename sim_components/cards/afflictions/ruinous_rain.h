#pragma once
#include "../affliction.h"

class ruinous_rain : public affliction
{
public:
	double cursed_dmg_mult;
	ruinous_rain(sim_deck* deck, int deck_index);
};