#pragma once
#include <string>

class player_card_info
{
public:
	std::string name;
	int level;
	int cards;
	player_card_info(std::string, int, int);
};