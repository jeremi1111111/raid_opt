#pragma once
#include "../sim_card.h"

class affliction : public sim_card
{
public:
	affliction(const card_name name, sim_deck* deck, int deck_index);
	virtual bool is_dealing_dmg(int tap_count, int stack_expire_tap);
};