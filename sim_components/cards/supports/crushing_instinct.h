#pragma once
#include "../support.h"

class crushing_instinct : public support
{
public:
	double head_sup_adt;
	double torso_sup_adt;
	double burst_chance_mult;
	crushing_instinct(sim_deck* deck, int deck_index);
	double roll_boost(card_category category);
};