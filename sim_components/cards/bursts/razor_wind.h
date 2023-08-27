#pragma once
#include "../burst.h"

class razor_wind : public burst
{
public:
	double body_dmg_mult;
	razor_wind(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
};