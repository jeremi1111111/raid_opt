#pragma once
#include <vector>
#include "player_info.h"
#include "../game_info/enumerables.h"

class attack_details
{
	int max_taps;
	double base_dmg;
	std::vector<part_name> order;
public:
	attack_details(player_info* player, const std::vector<part_name>& order_template, int interval, int max_taps = 600);
	part_name get_part_name(int tap);
	double get_base_dmg();
	int get_max_taps();
};