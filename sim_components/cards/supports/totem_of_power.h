#pragma once
#include <unordered_map>
#include "../support.h"

class totem_of_power : public support
{
	double stack_duration;
	double spawn_rate;
	double randomness;
	std::vector<int> roll_pattern;
	std::vector<int>::iterator current;
	// delay to side borders
	static const std::unordered_map<part_name, std::pair<int, int>> base_delay_map;
	// delay to top (negative value) and bottom
	static const std::unordered_map<part_name, std::pair<int, int>> extra_delay_map;
public:
	totem_of_power(sim_deck* deck = nullptr, int deck_index = 0);

	bool roll(double modifier);
	int calculate_expire_tap(sim_stack* stack, int tap);
};