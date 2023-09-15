#pragma once
#include "../affliction.h"

class acid_drench : public affliction
{
public:
	acid_drench(sim_deck* deck, int deck_index);
	int calculate_expire_tap(sim_stack* stack, int tap);
};