#pragma once
#include <functional>
#include <vector>
#include "sim_deck.h"
#include "sim_titan.h"
#include "../game_info/card_info.h"
#include "../game_info/enumerables.h"
#include "../program/attack_details.h"
#include "../program/simulation.h"

class sim_deck;
class sim_stack;

class sim_card
{
protected:
	card_name name;
	card_category category;
	sim_deck* deck;
	int deck_index;
	double roll_chance;
	double duration;
	double delay;
	sim_card(card_name name, sim_deck* deck, int deck_index);
public:
	static std::vector<std::function<sim_card*()>> sim_card_builder;

	virtual double roll_boost(sim_card* card);
	virtual bool roll(double modifier);
	virtual int calculate_expire_tap(sim_stack* stack, int tap);

	int get_deck_index();
	card_category get_category();
};
