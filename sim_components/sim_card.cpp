#include "sim_card.h"
#include "sim_stack.h"
#include "cards/cards.h"
#include "../program/simulation.h"

std::vector<std::function<sim_card* ()>> sim_card::sim_card_builder = {
	[]() -> sim_card* {
		return new moon_beam(); },
	[]() -> sim_card* {
		return new totem_of_power(); }
};

// remember to update it and create constructors for each card
sim_card::sim_card(card_name name, sim_deck* deck, int deck_index)
	: name(name), deck(deck), deck_index(deck_index)
{
	card_info* ci = cards[static_cast<int>(name)];
	roll_chance = ci->chance;
	duration = ci->duration;
}

double sim_card::roll_boost(sim_card* card)
{
	return 1.0;
}

bool sim_card::roll(double modifier)
{
	if (dist(rng) >= roll_chance * modifier)
		return false;
	return true;
}

int sim_card::calculate_expire_tap(sim_stack* stack, int tap)
{
	if (tap - delay < 0)
		return -1;
	return tap + duration * 20;
}

card_category sim_card::get_category()
{
	return category;
}

int sim_card::get_deck_index()
{
	return deck_index;
}

