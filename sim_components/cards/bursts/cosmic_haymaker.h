#pragma once
#include "../burst.h"

class cosmic_haymaker : public burst
{
public:
	int tap_count_for_outburst;
	int tap_count = 0;
	cosmic_haymaker(sim_deck* deck, int deck_index);
	bool roll(sim_part* part, double modifier);
	//double calculate_dmg(sim_part* part, double modifier);
};