#pragma once
#include "../support.h"

class ancestral_favor : public support
{
public:
	double burst_sup_adt;
	double burst_chance_mult;
	ancestral_favor(sim_deck* deck, int deck_index);
	double roll_boost(card_category category);
};