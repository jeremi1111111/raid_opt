#include "burst.h"
//#include "../sim_part.h"
//
//burst::burst(const card_name name, sim_deck* deck, int deck_index, sim_titan* titan)
//	: sim_card::sim_card(name, deck, deck_index, titan)
//{
//	this->category = card_category::burst;
//}
//
//bool burst::roll(sim_part* part, double modifier)
//{
//	if (!sim_card::roll(part, modifier))
//		return false;
//	counter++;
//	return true;
//}
//
//void burst::add_stack(sim_part* part, int tap_count)
//{
//	if (part)
//		part->add_stack(this, tap_count + delay);
//}

burst::burst(card_name name, sim_deck* deck, int deck_index)
	: sim_card(name, deck, deck_index)
{
	category = card_category::burst;
}
