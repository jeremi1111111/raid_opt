#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_titan;
class sim_stack;
class sim_card;

class sim_part
{
public:
	part_name name;
	sim_titan* titan;
	double hp;
	double ap;
	bool is_cursed;
	//int tap_count;
	std::vector<sim_stack*> deck_stacks;
	sim_part(sim_titan* titan, part_name name);
	void add_stack(sim_card* card, int expire_tap);
	void remove_old_stacks(int tap);
	bool is_afflicted();
	int count_afflicted_stacks();
	void invalidate_afflictions();

	int get_stack_count(sim_card* card);
	double get_ap();
};