#pragma once
#include "../burst.h"

class moon_beam : public burst
{
public:
	double torso_dmg_mult;
	moon_beam(sim_deck* deck = nullptr, int deck_index = -1);
	//double calculate_dmg(sim_part* part, double modifier);
};