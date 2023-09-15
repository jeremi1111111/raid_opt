#include <iostream>
#include "purifying_blast.h"

purifying_blast::purifying_blast(sim_deck* deck, int deck_index)
	: burst(card_name::purifying_blast, deck, deck_index)
{
	dmg_adt_per_affliction = card_data->bonus_amount_c;
}

double purifying_blast::calculate_damage(sim_part* part, int tap, double modifier)
{
	if (tap != part->get_stack(this)->get_first())
		return 0;
	double sup = deck->calculate_support(this, part);
	double dmg = base_dmg * modifier * (1 + sup);
	int aff_count = part->get_affliction_stack_count();
	if (aff_count)
		dmg *= 1. + dmg_adt_per_affliction * aff_count;
	part->invalidate_afflictions();
	//return 0;
	total_dmg += dmg;
	return dmg;
}
