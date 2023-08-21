#pragma once
#include "declarations.h"
#include "enumerables.h"
#include "sim_titan.h"

class sim_part
{
public:
	part_name name;
	sim_titan* titan;
	//double hp;
	//double ap;
	//bool is_cursed;
	//int tap_count;
	//std::vector<int>* deck_stacks;
	sim_part(sim_titan* titan, part_name name);
	void remove_old_stacks(int tap);
};