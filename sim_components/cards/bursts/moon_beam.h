#pragma once
#include "../burst.h"

class moon_beam : public burst
{
public:
	double torso_dmg_mult;
	moon_beam(sim_deck* deck, int deck_index, sim_titan* titan);
	double calculate_dmg(sim_part* part, double modifier);
};