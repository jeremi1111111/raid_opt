#pragma once
#include "../burst.h"

class flak_shot : public burst
{
public:
	double richochet_dmg_mult;
	bool ricochet_flag;
	flak_shot(sim_deck* deck, int deck_index);
	bool roll(sim_part* part, double modifier);
	double calculate_dmg(sim_part* part, double modifier);
};