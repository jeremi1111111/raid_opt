#pragma once
#include "../burst.h"

class mirror_force : public burst
{
public:
	double dmg_mult_per_clanmate;
	double max_boost;
	// might wanna keep it somewhere else
	int clanmates = 35;
	mirror_force(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
};