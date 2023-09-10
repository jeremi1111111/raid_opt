#pragma once
#include "../burst.h"

class celestial_static : public burst
{
public:
	int charges_per_burst;
	int charges_per_tap;
	int max_charges;
	int charges = 0;
	//celestial_static(sim_deck* deck, int deck_index);
	//bool roll(sim_part* part, double modifier);
	//double calculate_dmg(sim_part* part, double modifier);
};