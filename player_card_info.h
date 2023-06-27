#pragma once
#include <string>
#include <vector>

class player_card_info
{
public:
	std::string name;
	int level;
	int cards;
	player_card_info(std::string, int, int);
};

extern std::vector<player_card_info*> player_info;