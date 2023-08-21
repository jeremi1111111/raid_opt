#pragma once
#include <vector>
#include "declarations.h"
//#include "enumerables.h"
#include "sim_card.h"
#include "sim_titan.h"

class sim_deck
{
public:
	std::vector<sim_card*> deck_cards;
	sim_deck(card_name c1, card_name c2, card_name c3);
	void simulate(double base_dmg, sim_titan* titan, int max_taps = 600);
};