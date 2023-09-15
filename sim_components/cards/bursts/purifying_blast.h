#pragma once
#include "../burst.h"

class purifying_blast : public burst
{
	double dmg_adt_per_affliction;
public:
	purifying_blast(sim_deck* deck = nullptr, int deck_index = 0);
	double calculate_damage(sim_part* part, int tap, double modifier);
	//double calculate_dmg(sim_part* part, double modifier);
};