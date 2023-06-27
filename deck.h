#pragma once
#include "player_card_info.h"

class deck
{
public:
	player_card_info* card_1, * card_2, * card_3;
	double total;
	deck(player_card_info*, player_card_info*, player_card_info*);
};