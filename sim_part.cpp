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
	auto aff_it = std::find_if(deck_stacks.begin(), deck_stacks.end(),
		[](sim_stack* st) { return st->card->card->category == "Affliction"; });
	//if ((c1->card->category == "Affliction" && !c1->active_stacks.empty()) ||
	//	(c2->card->category == "Affliction" && !c2->active_stacks.empty()) ||
	//	(c3->card->category == "Affliction" && !c3->active_stacks.empty()))
	if (aff_it == deck_stacks.end())
		return false;
	return true;
}

int sim_part::count_bursts()
{
	int counter = 0;
	for (sim_stack* st : deck_stacks)
		if (st->card->card->category == "Burst")
			counter += st->total_stack_count;
	//if (c1->card->category == "Burst")
	//	counter += c1->active_stacks.size();
	//if (c2->card->category == "Burst")
	//	counter += c2->active_stacks.size();
	//if (c3->card->category == "Burst")
	//	counter += c3->active_stacks.size();
	return counter;
}

int sim_part::count_afflicted_stacks()
{
	int counter = 0;
	for (sim_stack* st : deck_stacks)
		if (st->card->card->category == "Affliction")
			counter += st->total_stack_count;
	//if (c1->card->category == "Affliction")
	//	counter += c1->active_stacks.size();
	//if (c2->card->category == "Affliction")
	//	counter += c2->active_stacks.size();
	//if (c3->card->category == "Affliction")
	//	counter += c3->active_stacks.size();
	return counter;
}
