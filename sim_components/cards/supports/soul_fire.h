#pragma once
#include "../support.h"

class soul_fire : public support
{
public:
	double head_sup_adt;
	double torso_sup_adt;
	double affliction_chance_mult;
	soul_fire(sim_deck* deck, int deck_index);
	double roll_boost(card_category category);
};