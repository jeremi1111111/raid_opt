#pragma once
#include "../sim_card.h"

class burst : public sim_card
{
protected:
	double base_dmg;
	burst(card_name name, sim_deck* deck, int deck_index);
public:
	int get_max_stacks();
};