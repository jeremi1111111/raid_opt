#include "burst.h"

burst::burst(const card_name name, sim_deck* deck, int deck_index, sim_titan* titan)
	: sim_card::sim_card(name, deck, deck_index, titan)
{
}
