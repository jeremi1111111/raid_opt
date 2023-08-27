#pragma once
#include "../affliction.h"

class blazing_inferno : public affliction
{
public:
	double chance_per_burning_part;
	blazing_inferno(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
	bool roll(sim_part* part, double modifier = 1.);
};