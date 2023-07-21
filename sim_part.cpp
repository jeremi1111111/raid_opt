#include "sim_part.h"
//#include "sim_part.h"

sim_part::sim_part(sim_titan* parent, part_name name)
{
	this->parent = parent;
	this->name = name;
	this->hp = 0.;
	this->ap = 0.;
	this->is_cursed = false;
}

bool sim_part::is_afflicted()
{
	if ((c1->card->category == "Affliction" && !c1->active_stacks.empty()) ||
		(c2->card->category == "Affliction" && !c2->active_stacks.empty()) ||
		(c3->card->category == "Affliction" && !c3->active_stacks.empty()))
		return true;
	return false;
}

int sim_part::count_bursts()
{
	int counter = 0;
	if (c1->card->category == "Burst")
		counter += c1->active_stacks.size();
	if (c2->card->category == "Burst")
		counter += c2->active_stacks.size();
	if (c3->card->category == "Burst")
		counter += c3->active_stacks.size();
	return counter;
}

int sim_part::count_afflicted_stacks()
{
	int counter = 0;
	if (c1->card->category == "Affliction")
		counter += c1->active_stacks.size();
	if (c2->card->category == "Affliction")
		counter += c2->active_stacks.size();
	if (c3->card->category == "Affliction")
		counter += c3->active_stacks.size();
	return counter;
}
