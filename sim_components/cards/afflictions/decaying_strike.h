#pragma once
#include "../affliction.h"

class decaying_strike : public affliction
{
public:
	double max_dmg_exponent;
	double max_missing_hp;
	decaying_strike(sim_deck* deck, int deck_index);
};