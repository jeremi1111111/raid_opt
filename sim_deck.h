#pragma once
#include <vector>
#include "declarations.h"
#include "player_card_info.h"
#include "sim_card.h"

class sim_deck
{
public:
	double total_damage;
	std::vector<sim_card*> deck_cards;
	sim_deck(player_card_info* c1, player_card_info* c2, player_card_info* c3);
	void simulate(std::vector<sim_part*> attack_order, int interval = 1, int max_taps = 600);
};