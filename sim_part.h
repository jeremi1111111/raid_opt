#pragma once
#include <string>
#include "declarations.h"
#include "sim_titan.h"
#include "sim_card.h"
#include "enumerates.h"

class sim_part
{
public:
	sim_titan* parent;
	part_name name;
	double hp;
	double ap;
	bool is_cursed;
	int tap_count = 0;
	std::vector<sim_stack*> deck_stacks;
	sim_part(sim_titan* parent, part_name name);
	bool is_afflicted();
	int count_bursts();
	int count_afflicted_stacks();
};

// ideas