#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "card_info.h"

// holds player cards statistics
class player_card_info
{
public:
	int index;
	card_info* card_data;
	size_t level;
	int card_shards;

	player_card_info(int ind, size_t lvl, int cds);
	bool roll(double modifier, int counter);
	double calculate_damage(double modifier, int counter_multiplicative, bool flag_b, int counter_additive);
	double calculate_support(double modifier, bool flag_a, int counter_additive);
};

extern std::vector<player_card_info*> player_info;