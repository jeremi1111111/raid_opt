#include "sim_deck.h"

sim_deck::sim_deck(card_name c1, card_name c2, card_name c3)
{
	int index = static_cast<int>(c1);
	//this->deck_cards = {
	//	//change it to this vector builder dings
	//	sim_card::sim_card_builder(c1, this, 0),
	//	sim_card::sim_card_builder(c2, this, 1),
	//	sim_card::sim_card_builder(c3, this, 2),
	//};
}

std::vector<double> sim_deck::calculate_roll_modifiers()
{
	return {
		deck_cards[1]->roll_boost(deck_cards[0]) * deck_cards[2]->roll_boost(deck_cards[0]),
		deck_cards[0]->roll_boost(deck_cards[1]) * deck_cards[2]->roll_boost(deck_cards[1]),
		deck_cards[0]->roll_boost(deck_cards[2]) * deck_cards[1]->roll_boost(deck_cards[2])
	};
}

std::vector<bool> sim_deck::roll_deck(sim_part* part, std::vector<double> modifier)
{
	return {
		deck_cards[0]->roll(part, modifier[0]),
		deck_cards[1]->roll(part, modifier[1]),
		deck_cards[2]->roll(part, modifier[2]),
	};
}

std::vector<double> sim_deck::calculate_dmg(sim_part* part, int tap, double base_dmg)
{
	std::vector<double> dmg(3, 0);
	for (sim_card* sc : deck_cards)
		if (sc->is_dealing_dmg(part, tap))
			dmg[sc->get_deck_index()] = sc->calculate_dmg(part, tap, base_dmg);
	return dmg;
}

void sim_deck::simulate(attack_details* attack, sim_titan* titan)
{
	std::vector<double> roll_modifier = calculate_roll_modifiers();

	sim_part* tapped_part = titan->get_part(attack->get_part_name());
	int max_taps = attack->get_max_taps();
	double base_dmg = attack->get_base_dmg();

	for (int tap = 0; tap < max_taps; tap++)
	{
		titan->remove_old_stacks(tap);

		std::vector<bool> roll_result = roll_deck(tapped_part, roll_modifier);

		for (sim_card* sc : deck_cards)
			if (roll_result[sc->get_deck_index()])
				sc->add_stack(tapped_part, tap);

		for (sim_part* sp : titan->parts)
			std::vector<double> dmg = calculate_dmg(sp, tap, base_dmg);
	}
}

int sim_deck::total_burst_count()
{
	int counter = 0;
	for (sim_card* sc : deck_cards)
		if (sc->get_category() == card_category::burst)
			counter += sc->get_counter();
	return counter;
}