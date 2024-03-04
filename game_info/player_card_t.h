#pragma once
#include <vector>
#include "enumerables.h"

class player_card_t
{
public:
	const card_name name;
	int level;
	int card_shards;
	
	player_card_t(const card_name& name, int level, int card_shards)
		: name(name), level(level), card_shards(card_shards)
	{}

	int get_level()
	{
		return level;
	}
};

extern std::vector<player_card_t*> player_cards;