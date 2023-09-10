#include "sim_part.h"
#include "sim_titan.h"
#include "sim_stack.h"
#include "sim_card.h"

//const std::vector<int> sim_part::pos_y = {
//	550, 890, 620, 965, 620, 965, 1205, 1205
//};

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

bool sim_part::is_afflicted()
{
	for (sim_stack* st : this->deck_stacks)
		if (st->get_category() == card_category::affliction)
			if (!st->is_empty())
				return true;
	return false;
}

sim_stack* sim_part::get_stack(sim_card* card)
{
	return deck_stacks[card->get_deck_index()];
}

void sim_part::add_stack(sim_card* card, int tap)
{
	sim_stack* stack = get_stack(card);
	int expire_tap = card->calculate_expire_tap(stack, tap);
	if (expire_tap < 0)
		return;
	get_stack(card)->add_stack(expire_tap);
}

part_name sim_part::get_part_name()
{
	return name;
}

//int sim_part::get_pos_y()
//{
//	return pos_y[static_cast<int>(name)];
//}

/*
void sim_part::add_stack(sim_card* card, int expire_tap)
{
	//deck_stacks[card->deck_index]->add_stack(expire_tap);
}

void sim_part::remove_old_stacks(int tap)
{
}

void sim_part::remove_first_stack(sim_card* card)
{
	//deck_stacks[card->get_deck_index()]->remove_first_stack();
}



double sim_part::get_ap()
{
	return ap;
}

int sim_part::count_afflicted_stacks()
{
	//int counter = 0;
	//for (sim_stack* st : this->deck_stacks)
	//	if (st->card->category == card_category::affliction)
	//		counter += st->active_stacks.size();
	//return counter;
	return 0;
}

void sim_part::invalidate_afflictions()
{
	//for (sim_stack* st : this->deck_stacks)
	//	if (st->card->category == card_category::affliction)
	//		st->active_stacks.assign(st->active_stacks.size(), 0);
}

*/