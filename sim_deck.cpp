#include "sim_deck.h"

sim_deck::sim_deck(card_name& c1, card_name& c2, card_name& c3)
{
	this->deck_cards = {
		sim_card::sim_card_builder(c1, this, 0),
		sim_card::sim_card_builder(c2, this, 1),
		sim_card::sim_card_builder(c3, this, 2),
	};
}

void sim_deck::simulate(std::vector<sim_part*> attack_order, int interval, int max_taps)
{
	sim_titan* titan = attack_order[0]->titan;
	sim_part* attacked_part = attack_order[0];

	double roll_modifier[] = { 1., 1., 1. };
	// might wanna have that in sim_card, not sim_deck (as roll_boost())
	//for (sim_card* sc : deck_cards)
	//	if (sc->is_burst)
	//		for (sim_card* bc : deck_cards)
	//		{
	//			if (bc->is_support)
	//				if (bc->card->name == card_name::crushing_instinct || bc->card->name == card_name::ancestral_favor)
	//					roll_modifier[sc->deck_index] *= bc->card->bonus_amount_c;
	//		}
	//	else if (sc->is_affliction)
	//		for (sim_card* bc : deck_cards)
	//		{
	//			if (bc->is_support)
	//				if (bc->card->name == card_name::soul_fire || bc->card->name == card_name::rancid_gas)
	//					roll_modifier[sc->deck_index] *= bc->card->bonus_amount_c;
	//		}

	for (int tap = 0; tap < max_taps; tap++)
	{
		titan->remove_old_stacks(tap);

		bool roll_result[] = { false, false, false };
		for (sim_card* sc : deck_cards)
			if (sc->roll(roll_modifier[sc->deck_index]) == true)
			{
				roll_result[sc->deck_index] = true;
				//sc->add_stack(attacked_part, tap);
			}

		double support[] = { 1., 1., 1. };
		//for (sim_card* sc : deck_cards)
		//	if (sc->is_support)
		double dmg[] = { 0, 0, 0 };
	}
}
