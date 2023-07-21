#include "sim_card.h"

//std::random_device rd;
//std::mt19937 rng(rd());
//std::uniform_real_distribution<double> dist(0., 1.);

// IMPORTANT!!!
// APPLY DAMAGES TO PARTS

sim_card::sim_card(int index)
{
	this->card = cards[index];
	this->player_card = player_info[index];
}

bool sim_card::roll(sim_part* titan_part, double modifier)
{
	return dist(rng) < this->card->chance * modifier;
}

double sim_card::calculate_dmg(sim_part* titan_part, double modifier)
{
	return 0.0;
}

double sim_card::calculate_support(double modifier)
{
	return 1.0;
}

double moon_beam::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (titan_part->name == part_name::torso)
		dmg *= card->bonus_amount_c;
	return dmg * modifier;
}

double fragmentize::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (titan_part->ap > 0.)
	{
		dmg *= card->bonus_amount_c;
		if (titan_part->is_cursed)
			dmg *= card->bonus_amount_b[player_card->level];
	}
	return dmg * modifier;
}

double skull_bash::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (titan_part->name == part_name::head)
		dmg *= card->bonus_amount_c;
	return dmg * modifier;
}

double razor_wind::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (titan_part->ap == 0.)
		dmg *= card->bonus_amount_c;
	return dmg * modifier;
}

bool whip_of_lightning::roll(sim_part* titan_part, double modifier)
{
	double chance = card->chance;
	int counter = titan_part->parent->count_afflicted();
	if (counter)
		chance += std::min(card->bonus_amount_b[player_card->level] * counter, card->bonus_amount_c);
	return dist(rng) < chance * modifier;
}

double whip_of_lightning::calculate_dmg(sim_part* titan_part, double modifier)
{
	return card->bonus_amount_a[player_card->level] * modifier;
}

double clanship_barrage::calculate_dmg(sim_part* titan_part, double modifier)
{
	// this can be changed, so that each burst increases some total burst count of attack (could be done in simulation)
	double dmg = card->bonus_amount_a[player_card->level];
	int counter = titan_part->parent->count_total_bursts();
	if (counter)
		dmg *= 1. + card->bonus_amount_c * counter;
	return dmg * modifier;
}

double purifying_blast::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	int counter = titan_part->count_afflicted_stacks();
	if (counter)
		dmg *= 1. + card->bonus_amount_c * counter;
	return dmg * modifier;
}

double psychic_shackles::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (titan_part->name != part_name::head &&
		titan_part->name != part_name::torso)
		dmg *= card->bonus_amount_c;
	return dmg * modifier;
}

double flak_shot::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (!ricochet_flag)
	{
		ricochet_flag = true;
		return dmg * modifier + calculate_dmg(titan_part->parent->random_part(titan_part, true), modifier);
	}
	ricochet_flag = false;
	return dmg * card->bonus_amount_c * modifier;
}

double cosmic_haymaker::calculate_dmg(sim_part* titan_part, double modifier)
{
	if (titan_part->parent->count_all_taps() % int(card->bonus_amount_c))
		return card->bonus_amount_a[player_card->level] * modifier;
	return 0.0;
}

double chain_of_vengeance::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (previously_hit.size() != card->bonus_amount_d)
	{
		bool was_previously_hit = false;
		for (sim_part* part : previously_hit)
			if (part == titan_part)
			{
				break;
				was_previously_hit = true;
			}
		if (!was_previously_hit)
			previously_hit.push_back(titan_part);
	}
	// here assign damages to parts
	return dmg * modifier;
}

mirror_force::mirror_force(int index, int clanmates) : sim_card::sim_card(index)
{
	this->clanmates = clanmates;
}

double mirror_force::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = card->bonus_amount_a[player_card->level];
	if (clanmates)
		dmg *= 1. + std::min(clanmates * card->bonus_amount_c, card->bonus_amount_d);
	return dmg * modifier;
}

double celestial_static::calculate_dmg(sim_part* titan_part, double modifier)
{
	if (titan_part->ap == 0.)
	{
		charges = std::min(charges + card->bonus_amount_d, card->bonus_amount_e);
		return 0.0;
	}
	if (charges - card->bonus_amount_c < 0)
		return 0.0;
	double dmg = card->bonus_amount_a[player_card->level];
	charges -= card->bonus_amount_c;
	return dmg * modifier;
}
