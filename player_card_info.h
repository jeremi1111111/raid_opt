#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "declarations.h"
#include "card_info.h"

class player_card_info
{
public:
	card_name name;
	int level;
	int card_shards;
	player_card_info(const card_name& name, int level, int card_shards)
		: name(name), level(level), card_shards(card_shards)
	{}
};

extern std::vector<player_card_info*> player_info;