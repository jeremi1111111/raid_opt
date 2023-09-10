#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_card;
class sim_titan;
class sim_part;
class attack_details;

class sim_deck
{
	sim_titan* titan;
	attack_details* attack;
	std::vector<sim_card*> deck_cards;
public:
	sim_deck(card_name c1, card_name c2, card_name c3);
	std::vector<double> calculate_roll_modifiers();
	std::vector<bool> roll_deck(std::vector<double> modifier);
	void simulate();
	/*
	std::vector<double> calculate_dmg(sim_part* part, int tap, double base_dmg = 1.);
	int total_burst_count();
	*/

	sim_titan* get_titan();
	attack_details* get_attack();
};