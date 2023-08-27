#pragma once
#include "../support.h"

class skeletal_smash : public support
{
public:
	double armor_sup_adt;
	double armor_sup_adt_if_dead_parts;
	skeletal_smash(sim_deck* deck, int deck_index);
};