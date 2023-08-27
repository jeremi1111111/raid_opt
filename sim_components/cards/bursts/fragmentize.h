#pragma once
#include "../burst.h"

class fragmentize : public burst
{
public:
	double cursed_dmg_mult;
	double armor_dmg_mult;
	fragmentize(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
};