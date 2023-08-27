#pragma once
#include "../support.h"

class astral_echo : public support
{
public:
	double all_sup_adt;
	int max_charges;
	double all_chance_mult;
	int charges;
	astral_echo(sim_deck* deck, int deck_index);
};