#pragma once
#include "../sim_card.h"

class burst : public sim_card
{
public:
	burst(const card_name name, sim_deck* deck, int deck_index, sim_titan* titan);
	virtual bool roll(sim_part* part, double modifier = 1.);
	virtual void add_stack(sim_part* part, int tap_count);
	virtual bool is_dealing_dmg(int tap_count, int stack_expire_tap);
	virtual double calculate_dmg(sim_part* part, double modifier = 1.);
};