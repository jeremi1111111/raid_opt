#pragma once
//#include <unordered_map>
#include "../support.h"

class totem_of_power : public support
{
	double all_sup_adt;
	double stack_duration;
	double spawn_rate;
	double randomness;
	std::vector<int> roll_pattern;
	std::vector<int>::iterator current;
	// delay to left and right edge
	static const std::vector<std::pair<int, int>> delay_x_vec;
	// delay to top and bottom
	static const std::vector<std::pair<int, int>> delay_y_vec;
	// delay offset inside hitbox
	static std::uniform_int_distribution<int> hitbox_delay_roller;
	// past this value, delay doesn't need to be calculated
	static const int delay_threshold;
public:
	totem_of_power(sim_deck* deck = nullptr, int deck_index = 0);

	bool roll(double modifier);
	int calculate_expire_tap(sim_stack* stack, int tap);
	double calculate_support(sim_part* part, sim_card* other);
	int get_max_stacks();
};