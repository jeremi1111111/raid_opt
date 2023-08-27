#pragma once
#include <functional>
#include <vector>
#include "../game_info/enumerables.h"

class sim_deck;
class sim_titan;
class sim_part;

class sim_card
{
//protected:
public:
	card_name name;
	sim_deck* deck;
	int deck_index;
	card_category category;
	double roll_chance;
	double base_effect;
	double duration;
	int max_stacks;
	int delay = 0;
	int counter = 0;
	sim_titan* titan;

	static std::vector<std::function<sim_card* (sim_deck*, int, sim_titan*)>> sim_card_builder;
	//static sim_card* sim_card_builder(card_name name, sim_deck* deck, int deck_index);

	sim_card(card_name name, sim_deck* deck, int deck_index, sim_titan* titan);
	virtual bool roll(sim_part* part, double modifier = 1.);
	virtual void add_stack(sim_part* part, int tap_count);
	virtual bool is_dealing_dmg(sim_part* part, int tap_count);
	//virtual void remove_stacks(sim_part* titan_part, int tap_count);
	//it's important to remember that effects of some cards are dalayed
	virtual double roll_boost(sim_card* card);
	virtual double calculate_dmg(sim_part* part, int tap, double base_dmg = 1.);
	virtual double calculate_support(sim_part* part, sim_card* other_card, double modifier = 1.);

	int get_deck_index();
	int get_max_stacks();
	card_category get_category();
	int get_counter();
};
