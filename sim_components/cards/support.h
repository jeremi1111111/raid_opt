#pragma once
#include "../sim_card.h"

class support : public sim_card
{
protected:
	support(card_name name, sim_deck* deck, int deck_index);
public:
	bool roll(double modifier, sim_part* part);
	int get_max_stacks();
};