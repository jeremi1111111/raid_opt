#include "sim_card.h"
#include "sim_stack.h"
#include "cards/cards.h"
#include "../program/simulation.h"

std::vector<std::function<sim_card* (sim_deck*, int)>> sim_card::sim_card_builder = {
	[](sim_deck* deck, int deck_index) -> sim_card* {
		return new moon_beam(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card* {
		return new purifying_blast(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card* {
		return new acid_drench(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card* {
		return new totem_of_power(deck, deck_index); }
};

// remember to update it and create constructors for each card
sim_card::sim_card(card_name name, sim_deck* deck, int deck_index)
	: name(name), deck(deck), deck_index(deck_index), total_dmg(0)
{
	int index = static_cast<int>(name);
	card_data = cards[index];
	level = player_cards[index]->get_level() - 1;
	max_stacks = card_data->max_stacks;
	duration = card_data->duration;
	roll_chance = card_data->chance;
}

double sim_card::roll_boost(sim_card* card)
{
	return 1.0;
}

bool sim_card::roll(double modifier, sim_part* part)
{
	if (dist(rng) >= roll_chance * modifier)
		return false;
	return true;
}

int sim_card::calculate_expire_tap(sim_stack* stack, int tap)
{
	return tap + duration * 20;
}

double sim_card::calculate_support(sim_part* part, sim_card* other)
{
	return 0.0;
}

double sim_card::calculate_damage(sim_part* part, int tap, double modifier)
{
	return 0.0;
}

card_category sim_card::get_category()
{
	return category;
}

int sim_card::get_max_stacks()
{
	return max_stacks;
}

card_name sim_card::get_name()
{
	return name;
}

double sim_card::get_dmg_dealt()
{
	return total_dmg;
}

int sim_card::get_deck_index()
{
	return deck_index;
}

