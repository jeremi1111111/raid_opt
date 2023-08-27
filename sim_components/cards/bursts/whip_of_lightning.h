#pragma once
#include "../burst.h"

class whip_of_lightning : public burst
{
public:
	double chance_per_afflicted_part;
	double max_bonus_chance;
	whip_of_lightning(sim_deck* deck, int deck_index);
	bool roll(sim_part* part, double modifier);
	//double calculate_dmg(sim_part* part, double modifier);
};