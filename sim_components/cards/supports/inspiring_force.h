#pragma once
#include "../support.h"

class inspiring_force : public support
{
public:
	double body_sup_adt;
	inspiring_force(sim_deck* deck, int deck_index);
};