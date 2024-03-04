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
//		part->remove_first(this);
//	part->add_stack(this, tap_count + duration * 20 + delay);
//}

affliction::affliction(card_name name, sim_deck* deck, int deck_index)
	: sim_card(name, deck, deck_index)
{
	category = card_category::affliction;
	base_dmg = card_data->get_bonus_amount('a', level);
}

double affliction::calculate_damage(sim_part* part, int tap, double modifier)
{
	//return 0.;
	double sup = deck->calculate_support(this, part);
	double dmg = base_dmg * part->get_stack(this)->size() * modifier * (1 + sup) / 20;
	total_dmg += dmg;
	return dmg;
}
