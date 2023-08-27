#include "moon_beam.h"

moon_beam::moon_beam(sim_deck* deck, int deck_index, sim_titan* titan)
	: burst(card_name::moon_beam, deck, deck_index, titan)
{
}
