#pragma once
#include "../burst.h"

class whip_of_lightning : public burst
{
	double chance_per_afflicted_part;
	double max_bonus_chance;
public:
	whip_of_lightning(sim_deck* deck, int deck_index);
	bool roll(double modifier, sim_part* part);
};