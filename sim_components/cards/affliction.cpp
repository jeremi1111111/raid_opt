#include "affliction.h"
//#include "affliction.h"
//#include "../sim_part.h"
//
//affliction::affliction(const card_name name, sim_deck* deck, int deck_index, sim_titan* titan)
//	: sim_card(name, deck, deck_index, titan)
//{
//	this->category = card_category::affliction;
//}
//
//void affliction::add_stack(sim_part* part, int tap_count)
//{
//	if (!part)
//		return;
//	if (part->get_stack_size(this) == max_stacks)
//		part->remove_first_stack(this);
//	part->add_stack(this, tap_count + duration * 20 + delay);
//}

affliction::affliction(card_name name, sim_deck* deck, int deck_index)
	: sim_card(name, deck, deck_index)
{
	category = card_category::affliction;
}
