#pragma once
#include "../burst.h"

class chain_of_vengeance : public burst
{
public:
	int max_targets;
	std::vector<part_name> previously_hit;
	//chain_of_vengeance(sim_deck* deck, int deck_index);
	//bool roll(sim_part* part, double modifier);
	//double calculate_dmg(sim_part* part, double modifier);
};