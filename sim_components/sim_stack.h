#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_card;
class sim_part;

class sim_stack
{
	sim_part* part;
	sim_card* card;
	std::vector<int> active_stacks;
public:
	sim_stack(sim_part* part, sim_card* card)
		: part(part), card(card)
	{}

	bool is_full();
	bool is_empty();
	int size();
	void add_stack(int tap);
	void remove_first_stack();

	card_category get_category();
	sim_part* get_part();
};

