#pragma once
#include <vector>
#include "enumerables.h"

class player_card_info
{
public:
	const card_name name;
	int level;
	int card_shards;
	
	player_card_info(const card_name& name, int level, int card_shards)
		: name(name), level(level), card_shards(card_shards)
	{}

	int get_level()
	{
		return level;
	}
};

extern std::vector<player_card_info*> player_cards;