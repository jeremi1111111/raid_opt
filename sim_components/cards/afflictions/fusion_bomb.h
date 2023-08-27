#pragma once
#include "../affliction.h"

class fusion_bomb : public affliction
{
public:
	double refresh_chance;
	fusion_bomb(sim_deck* deck, int deck_index);
};