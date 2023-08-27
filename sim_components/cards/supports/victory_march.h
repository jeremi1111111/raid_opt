#pragma once
#include "../support.h"

class victory_march : public support
{
public:
	double all_sup_adt;
	double all_sup_adt_per_dead_part;
	victory_march(sim_deck* deck, int deck_index);
};