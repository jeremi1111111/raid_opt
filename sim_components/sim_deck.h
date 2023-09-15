#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_card;
class sim_titan;
class sim_part;
class attack_details;

class sim_deck
{
	std::vector<sim_card*> deck_cards;
	sim_titan* titan;
	attack_details* attack;
	double tap_dmg;
public:
	sim_deck(std::vector<int> card_indexes, sim_titan* titan, attack_details* attack);
	std::vector<double> calculate_roll_modifiers();
	std::vector<bool> roll_deck(std::vector<double> modifier);
	double calculate_support(sim_card* card, sim_part* part);
	double simulate();
	/*
	std::vector<double> calculate_dmg(sim_part* part, int tap, double base_dmg = 1.);
	int total_burst_count();
	*/

	sim_titan* get_titan();
	attack_details* get_attack();
	std::vector<sim_card*> get_deck_cards();
	double get_tap_dmg();
};