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
	sim_stack(sim_part* part, sim_card* card);
	bool is_full();
	bool empty();
	int size();
	void add_stack(int tap);
	void remove_first();
	void remove_stacks(int tap);
	double calculate_dmg(double base_dmg, int tap);

	card_category get_category();
	sim_part* get_part();
	void set_stacks(int tap);
	card_name get_name();
	int get_first();
};

