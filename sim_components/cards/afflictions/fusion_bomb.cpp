#include "fusion_bomb.h"

bool fusion_bomb::roll(double modifier, sim_part* part)
{
	if (!part->get_stack(this)->empty())
		if (dist(rng) >= refresh_chance * modifier)
			return false;
		else
			return true;
	return sim_card::roll(modifier, part);
}
