#pragma once
#include "../sim_card.h"

class affliction : public sim_card
{
protected:
	affliction(card_name name, sim_deck* deck, int deck_index);
public:
};