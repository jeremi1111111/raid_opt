#pragma once
#include "../sim_card.h"

class affliction : public sim_card
{
protected:
	double base_dmg;
	affliction(card_name name, sim_deck* deck, int deck_index);
public:
	double calculate_damage(sim_part* part, int tap, double modifier);
};