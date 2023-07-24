#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "card_info.h"

class player_card_info
{
public:
	int index;
	int level;
	int card_shards;
	player_card_info(std::string nam, int lvl, int cds);
};

extern std::vector<player_card_info*> player_info;