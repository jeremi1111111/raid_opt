#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_card;
class sim_titan;
class sim_part;
class attack_details;

class sim_deck
{
public:
	std::vector<sim_card*> deck_cards;
	sim_deck(card_name c1, card_name c2, card_name c3);
	std::vector<double> calculate_roll_modifiers();
	std::vector<bool> roll_deck(sim_part* part, std::vector<double> modifier);
	std::vector<double> calculate_dmg(sim_part* part, int tap, double base_dmg = 1.);
	void simulate(attack_details* attack, sim_titan* titan);
	int total_burst_count();
};