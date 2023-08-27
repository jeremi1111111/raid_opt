#pragma once
#include "../support.h"

class rancid_gas : public support
{
public:
	double affliction_sup_adt;
	double affliction_chance_mult;
	rancid_gas(sim_deck* deck, int deck_index);
	double roll_boost(card_category category);
};