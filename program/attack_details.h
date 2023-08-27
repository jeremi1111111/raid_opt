#pragma once
#include <vector>
#include "player_info.h"
#include "../game_info/enumerables.h"

class attack_details
{
	std::vector<part_name> order;
	int interval;
	int max_taps;
	double base_dmg;
	int counter;
	std::vector<part_name>::iterator current;
public:
	attack_details(player_info* player, const std::vector<part_name>& order, int interval, int max_taps = 600);
	void progress();
	part_name get_part_name();
	double get_base_dmg();
	int get_max_taps();
};

