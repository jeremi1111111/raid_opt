#pragma once
#include "../sim_card.h"

class support : public sim_card
{
public:
	support(const card_name name, sim_deck* deck, int deck_index);
	virtual double roll_boost(card_category category);
};