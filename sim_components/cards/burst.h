#pragma once
#include "../sim_card.h"

class burst : public sim_card
{
protected:
	burst(card_name name, sim_deck* deck, int deck_index);
public:
};