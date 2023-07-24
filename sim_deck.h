#pragma once
#include <vector>
#include "declarations.h"
#include "player_card_info.h"

class deck
{
public:
	double total_damage;
	std::vector<player_card_info*> deck_cards;
	deck(player_card_info* c1, player_card_info* c2, player_card_info* c3);
};