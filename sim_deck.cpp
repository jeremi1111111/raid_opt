#include "sim_deck.h"

sim_deck::sim_deck(card_name c1, card_name c2, card_name c3)
{
	this->deck_cards = {
		sim_card::sim_card_builder(c1, this, 0),
		sim_card::sim_card_builder(c2, this, 1),
		sim_card::sim_card_builder(c3, this, 2),
	};
}

void sim_deck::simulate(double base_dmg, sim_titan* titan, int max_taps)
{
	double roll_modifier[] = { 1., 1., 1. };
	for (sim_card* sc : this->deck_cards)
		if (sc->name == card_name::crushing_instinct || sc->name == card_name::ancestral_favor)
			for (sim_card* cc : this->deck_cards)
			{
				if (cc->category == card_category::burst)
					roll_modifier[cc->deck_index] *= sc->roll_boost();
			}
		else if (sc->name == card_name::soul_fire || sc->name == card_name::rancid_gas)
			for (sim_card* cc : this->deck_cards)
			{
				if (cc->category == card_category::affliction)
					roll_modifier[cc->deck_index] *= sc->roll_boost();
			}

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
