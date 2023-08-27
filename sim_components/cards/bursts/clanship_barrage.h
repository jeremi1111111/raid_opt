#pragma once
#include "../burst.h"

class clanship_barrage : public burst
{
public:
	double dmg_adt_per_burst;
	clanship_barrage(sim_deck* deck, int deck_index);
	double calculate_dmg(sim_part* part, double modifier);
};