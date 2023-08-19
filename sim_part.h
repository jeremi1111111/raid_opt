#pragma once
#include <string>
#include "declarations.h"
#include "sim_titan.h"
#include "sim_card.h"
#include "enumerates.h"

class sim_part
{
public:
	sim_titan* titan;
	part_name name;
	//double hp;
	//double ap;
	//bool is_cursed;
	//int tap_count;
	//std::vector<int>* deck_stacks;
	sim_part(sim_titan* titan, part_name name);
	void remove_old_stacks(int tap);
};