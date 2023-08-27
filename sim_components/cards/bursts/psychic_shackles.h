#pragma once
#include "../burst.h"

class psychic_shackles : public burst
{
public:
	double limb_dmg_mult;
	psychic_shackles(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
};