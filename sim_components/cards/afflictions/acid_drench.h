#pragma once
#include "../affliction.h"

class acid_drench : public affliction
{
public:
	acid_drench(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};