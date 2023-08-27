#pragma once
#include "../affliction.h"

class ravenous_swarm : public affliction
{
public:
	ravenous_swarm(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};