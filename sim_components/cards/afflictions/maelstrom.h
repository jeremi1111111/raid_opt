#pragma once
#include "../affliction.h"

class maelstrom : public affliction
{
public:
	double sup_adt_per_stack;
	maelstrom(sim_deck* deck, int deck_index);
};