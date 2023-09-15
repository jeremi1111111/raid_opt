#include "support.h"

support::support(card_name name, sim_deck* deck, int deck_index)
	: sim_card(name, deck, deck_index)
{
	category = card_category::support;
}

bool support::roll(double modifier)
{
	return false;
}

int support::get_max_stacks()
{
	return 0;
}
