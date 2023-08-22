#include "sim_part.h"

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

bool sim_part::is_afflicted()
{
	for (sim_stack* st : this->deck_stacks)
		if (st->card->category == card_category::affliction)
			if (!st->active_stacks.empty())
				return true;
	return false;
}

int sim_part::count_afflicted_stacks()
{
	int counter = 0;
	for (sim_stack* st : this->deck_stacks)
		if (st->card->category == card_category::affliction)
			counter += st->active_stacks.size();
	return counter;
}

void sim_part::invalidate_afflictions()
{
	for (sim_stack* st : this->deck_stacks)
		if (st->card->category == card_category::affliction)
			st->active_stacks.assign(st->active_stacks.size(), 0);
}
