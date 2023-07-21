#pragma once
#include <vector>
#include "player_card_info.h"

class deck
{
public:
	std::vector<player_card_info*> deck_cards;
	double total_damage;
	deck(player_card_info* c1, player_card_info* c2, player_card_info* c3);
};