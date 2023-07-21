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
	sim_card* c1;
	sim_card* c2;
	sim_card* c3;
	sim_part(sim_titan* parent, part_name name);
	bool is_afflicted();
	int count_bursts();
	int count_afflicted_stacks();
};

// ideas
