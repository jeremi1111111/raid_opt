#pragma once
#include "../support.h"

class totem_of_power : public support
{
public:
	double stack_duration;
	double spawn_rate;
	double randomness;
	totem_of_power(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};