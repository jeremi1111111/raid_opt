#pragma once
#include "../affliction.h"

class fusion_bomb : public affliction
{
	double refresh_chance;
public:
	fusion_bomb(sim_deck* deck, int deck_index);
	bool roll(double modifier, sim_part* part);
};