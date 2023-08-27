#pragma once
#include "../support.h"

class team_tactics : public support
{
public:
	double all_sup_adt;
	team_tactics(sim_deck* deck, int deck_index);
};