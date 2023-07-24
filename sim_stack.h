#pragma once
#include <vector>
#include "declarations.h"

class sim_stack
{
public:
	sim_card* card;
	std::vector<int> active_stacks;
	int total_stack_count;
	sim_stack(sim_card* card);
};

