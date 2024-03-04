#include "sim_deck.h"
#include "sim_card.h"
#include "sim_part.h"
#include "sim_titan.h"
#include "../program/attack_details.h"

sim_deck::sim_deck(std::vector<int> card_indexes, sim_titan* titan, attack_details* attack)
	: titan(titan), attack(attack), tap_dmg(0)
{
	deck_cards.reserve(card_indexes.size());
	for (int index : card_indexes)
		deck_cards.push_back(sim_card::sim_card_builder[index](this, deck_cards.size()));
	//for (int i = 0; i < card_indexes.size(); i++)
	//	deck_cards.push_back(sim_card::sim_card_builder[card_indexes[i]](this, i));
}

sim_deck::~sim_deck()
{
	for (sim_card* card : deck_cards)
		delete card;
}

//sim_deck::sim_deck(card_name c1, card_name c2, card_name c3)
//{
//	int index = static_cast<int>(c1);
//	//this->deck_cards = {
//	//	//change it to this vector builder dings
//	//	sim_card::sim_card_builder(c1, this, 0),
//	//	sim_card::sim_card_builder(c2, this, 1),
//	//	sim_card::sim_card_builder(c3, this, 2),
//	//};
//}
//
std::vector<double> sim_deck::calculate_roll_modifiers()
{
	std::vector<double> roll_modifiers(deck_cards.size(), 1.);
	for (sim_card* card : deck_cards)
	{
		int index = card->get_deck_index();
		for (sim_card* sc : deck_cards)
			roll_modifiers[index] *= sc->roll_boost(card);
	}
	return roll_modifiers;

	//return {
	//	deck_cards[1]->roll_boost(deck_cards[0]) * deck_cards[2]->roll_boost(deck_cards[0]),
	//	deck_cards[0]->roll_boost(deck_cards[1]) * deck_cards[2]->roll_boost(deck_cards[1]),
	//	deck_cards[0]->roll_boost(deck_cards[2]) * deck_cards[1]->roll_boost(deck_cards[2])
	//};
}

std::vector<bool> sim_deck::roll_deck(std::vector<double> modifiers, sim_part* part)
{
	std::vector<bool> roll_results(deck_cards.size(), false);
	for (sim_card* card : deck_cards)
	{
		int index = card->get_deck_index();
		roll_results[index] = card->roll(modifiers[index], part);
	}
	return roll_results;

	//return {
	//	deck_cards[0]->roll(modifiers[0]),
	//	deck_cards[1]->roll(modifiers[1]),
	//	deck_cards[2]->roll(modifiers[2])
	//};
}

double sim_deck::calculate_support(sim_card* card, sim_part* part)
{
	double sup = 0.;
	for (sim_card* sc : deck_cards)
		sup += sc->calculate_support(part, card);
	return sup;
}

double sim_deck::simulate()
{
	//std::vector<double> roll_modifiers = calculate_roll_modifiers();
	std::vector<double> roll_modifiers = { 1., 1., 1. };

	int max_taps = attack->get_max_taps();
	double base_dmg = attack->get_base_dmg();

	for (int tap = 0; tap < max_taps; tap++)
	{
		part_name attacked_part_name = attack->get_part_name(tap);
		sim_part* attacked_part = titan->get_part(attacked_part_name);
		std::vector<bool> roll_results = roll_deck(roll_modifiers, attacked_part);

		for (int i = 0; i < roll_results.size(); i++)
			if (roll_results[i])
				attacked_part->add_stack(deck_cards[i], tap);

		for (sim_part* part : titan->get_parts())
			for (sim_stack* stack : part->get_deck_stacks())
				stack->calculate_dmg(base_dmg, tap);

		tap_dmg += base_dmg * calculate_support(nullptr, attacked_part);

		for (sim_part* part : titan->get_parts())
			for (sim_stack* stack : part->get_deck_stacks())
				stack->remove_stacks(tap);
	}
	double dmg = tap_dmg;
	for (sim_card* card : deck_cards)
		dmg += card->get_dmg_dealt();
	return dmg;
}
//
//int sim_deck::total_burst_count()
//{
//	int counter = 0;
//	for (sim_card* sc : deck_cards)
//		if (sc->get_category() == card_category::burst)
//			counter += sc->get_counter();
//	return counter;
//}
//
sim_titan* sim_deck::get_titan()
{
	return this->titan;
}

attack_details* sim_deck::get_attack()
{
	return this->attack;
}

std::vector<sim_card*> sim_deck::get_deck_cards()
{
	return deck_cards;
}

double sim_deck::get_tap_dmg()
{
	return tap_dmg;
}
