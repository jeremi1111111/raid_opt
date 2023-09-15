#pragma once
#include <functional>
#include <vector>
#include "sim_deck.h"
#include "sim_titan.h"
#include "sim_part.h"
#include "sim_stack.h"
#include "../game_info/card_info.h"
#include "../game_info/player_card_info.h"
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
	card_info* card_data;
	int level;
	int max_stacks;
	double duration;
	double roll_chance;
	double total_dmg;
	sim_card(card_name name, sim_deck* deck, int deck_index);
public:
	static std::vector<std::function<sim_card*(sim_deck*, int)>> sim_card_builder;

	virtual double roll_boost(sim_card* card);
	virtual bool roll(double modifier);
	virtual int calculate_expire_tap(sim_stack* stack, int tap);
	virtual double calculate_support(sim_part* part, sim_card* other);
	virtual double calculate_damage(sim_part* part, int tap, double modifier);

	int get_deck_index();
	card_category get_category();
	virtual int get_max_stacks();
	card_name get_name();
	double get_dmg_dealt();
};
