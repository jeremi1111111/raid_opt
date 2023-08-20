#pragma once
#include <vector>
#include "declarations.h"
#include "player_card_info.h"
#include "sim_card.h"

class sim_deck
{
public:
	std::vector<sim_card*> deck_cards;
	sim_deck(card_name& c1, card_name& c2, card_name& c3);
	void simulate(std::vector<sim_part*> attack_order, int interval = 1, int max_taps = 600);
};