#pragma once
//#include "declarations.h"
#include "sim_part.h"

class sim_card;
class sim_part;

class sim_stack
{
public:
	sim_part* part;
	sim_card* card;
	std::vector<int> active_stacks;
	sim_stack(sim_part* part, sim_card* card)
		: part(part), card(card)
	{}
	bool is_full();
	void add_stack(int expire_tap);
	void remove_first_stack();
	int size();
};

