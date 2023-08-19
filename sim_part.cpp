#include "sim_part.h"
//#include "sim_part.h"

sim_part::sim_part(sim_titan* titan, part_name name)
{
	this->titan = titan;
	this->name = name;
	//this->hp = 0.;
	//this->ap = 0.;
	//this->is_cursed = false;
	//this->tap_count = 0;
	//this->deck_stacks = new std::vector<int>[3];
}

void sim_part::remove_old_stacks(int tap)
{
}
