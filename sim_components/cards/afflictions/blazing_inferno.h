#pragma once
#include "../affliction.h"

class blazing_inferno : public affliction
{
	double chance_per_burning_part;
public:
	blazing_inferno(sim_deck* deck, int deck_index);
	bool roll(double modifier);
};