#include "sim_card.h"

// IMPORTANT!!!
// APPLY DAMAGES TO PARTS
// increase stack counters

sim_card* sim_card::sim_card_builder(card_name& name, sim_deck* deck, int deck_index)
{
	switch (name)
	{
	case card_name::moon_beam:
		return new moon_beam(name, deck, deck_index);
	default:
		return nullptr;
	}
}

sim_card::sim_card(const card_name& name, sim_deck* deck, int deck_index)
	: name(name), deck(deck), deck_index(deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->roll_chance = ci[index].chance;
}


bool sim_card::roll(double modifier)
{
	if (dist(rng) < (this->roll_chance * modifier))
		return true;
	return false;
}
/*
void sim_card::add_stack(sim_part* titan_part, int tap_count)
{
	//if (!titan_part)
	//	return;
	//std::vector<int>& stack = titan_part->deck_stacks[deck_index];
	//stack.push_back(tap_count + card->duration * 20);
	//if (stack.size() + 1 > card->max_stacks)
	//	stack.erase(stack.begin());
}

void sim_card::remove_stacks(sim_part* titan_part, int tap_count)
{
	//if (!titan_part)
	//	return;
	//std::vector<int>& stack = titan_part->deck_stacks[deck_index];
	//if (stack.empty())
	//	return;
	//auto new_end_iter =  std::remove_if(stack.begin(), stack.end(),
	//	[tap_count](int end_tap) { return end_tap <= tap_count; });
	//stack.erase(new_end_iter, stack.end());
}

double sim_card::calculate_dmg(sim_part* titan_part, double modifier)
{
	return 0.0;
}

double sim_card::calculate_support(double modifier)
{
	return 1.0;
}
*/
moon_beam::moon_beam(card_name& name, sim_deck* deck, int deck_index)
	: sim_card(name, deck, deck_index) 
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	int level = player_info[index]->level;
	this->category = card_category::burst;
	this->base_dmg_mult = ci->bonus_amount_a[level];
	this->torso_dmg_mult = ci->bonus_amount_c;
}

//double moon_beam::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (titan_part->name == part_name::torso)
//		dmg *= card->bonus_amount_c;
//	return dmg;
//}

//fragmentize::fragmentize(int deck_index) : sim_card(names["fragmentize"], deck_index) {}
//
//double fragmentize::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (titan_part->ap > 0.)
//	{
//		dmg *= card->bonus_amount_c;
//		if (titan_part->is_cursed)
//			dmg *= card->bonus_amount_b[player_card->level];
//	}
//	return dmg;
//}
//
//skull_bash::skull_bash(int deck_index) : sim_card(names["skull_bash"], deck_index) {}
//
//double skull_bash::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (titan_part->name == part_name::head)
//		dmg *= card->bonus_amount_c;
//	return dmg;
//}
//
//razor_wind::razor_wind(int deck_index) : sim_card(names["razor_wind"], deck_index) {}
//
//double razor_wind::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (titan_part->ap == 0.)
//		dmg *= card->bonus_amount_c;
//	return dmg;
//}
//
//whip_of_lightning::whip_of_lightning(int deck_index) : sim_card(names["whip_of_lightning"], deck_index) {}
//
//sim_part* whip_of_lightning::roll(sim_part* titan_part, double modifier)
//{
//	double chance = card->chance;
//	int counter = titan_part->parent->count_afflicted();
//	if (counter)
//		chance += std::min(card->bonus_amount_b[player_card->level] * counter, card->bonus_amount_c);
//	if (dist(rng) < (chance * modifier))
//		return titan_part;
//	return nullptr;
//}
//
//double whip_of_lightning::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	return dmg;
//}
//
//clanship_barrage::clanship_barrage(int deck_index) : sim_card(names["clanship_barrage"], deck_index) {}
//
//double clanship_barrage::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	// this can be changed, so that each burst increases some total burst count of attack (could be done in simulation)
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	int counter = titan_part->parent->count_total_bursts();
//	if (counter)
//		dmg *= 1. + card->bonus_amount_c * counter;
//	return dmg;
//}
//
//purifying_blast::purifying_blast(int deck_index) : sim_card(names["purifying_blast"], deck_index) {}
//
//double purifying_blast::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	int counter = titan_part->count_afflicted_stacks();
//	if (counter)
//		dmg *= 1. + card->bonus_amount_c * counter;
//	return dmg;
//}
//
//psychic_shackles::psychic_shackles(int deck_index) : sim_card(names["psychic_shackles"], deck_index) {}
//
//double psychic_shackles::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (titan_part->name != part_name::head &&
//		titan_part->name != part_name::torso)
//		dmg *= card->bonus_amount_c;
//	return dmg;
//}
//
//flak_shot::flak_shot(int deck_index) : sim_card(names["flak_shot"], deck_index)
//{
//	this->ricochet_flag = false;
//}
//
//double flak_shot::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (!ricochet_flag)
//	{
//		ricochet_flag = true;
//		dmg += calculate_dmg(titan_part->parent->random_part(titan_part, true), modifier);
//	}
//	else
//	{
//		ricochet_flag = false;
//		dmg *= card->bonus_amount_c;
//	}
//	return dmg;
//}
//
//cosmic_haymaker::cosmic_haymaker(int deck_index) : sim_card(names["cosmic_haymaker"], deck_index)
//{
//	tap_count = 0;
//}
//
//double cosmic_haymaker::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = 0.;
//	if (tap_count % int(card->bonus_amount_c) == 0)
//		dmg = card->bonus_amount_a[player_card->level] * modifier;
//	else
//		tap_count += 1;
//	return dmg;
//}
//
//chain_of_vengeance::chain_of_vengeance(int deck_index) : sim_card(names["chain_of_vengeance"], deck_index) {}
//
//double chain_of_vengeance::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (previously_hit.size() != card->bonus_amount_d)
//	{
//		bool was_previously_hit = false;
//		for (sim_part* part : previously_hit)
//			if (part == titan_part)
//			{
//				break;
//				was_previously_hit = true;
//			}
//		if (!was_previously_hit)
//			previously_hit.push_back(titan_part);
//	}
//	// here apply damages to parts
//	return dmg;
//}
//
//mirror_force::mirror_force(int deck_index) : sim_card(names["mirror_force"], deck_index)
//{
//	this->clanmates = 35;
//}
//
//double mirror_force::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	if (clanmates)
//		dmg *= 1. + std::min(clanmates * card->bonus_amount_c, card->bonus_amount_d);
//	return dmg;
//}
//
//celestial_static::celestial_static(int deck_index) : sim_card(names["celestial_static"], deck_index)
//{
//	this->charges = 0;
//}
//
//double celestial_static::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = 0.;
//	if (titan_part->ap == 0.)
//		charges = std::min(charges + card->bonus_amount_d, card->bonus_amount_e);
//	else if (charges - card->bonus_amount_c >= 0)
//	{
//		dmg = card->bonus_amount_a[player_card->level] * modifier;
//		charges -= card->bonus_amount_c;
//	}
//	return dmg;
//}
//
//blazing_inferno::blazing_inferno(int deck_index) : sim_card(names["blazing_inferno"], deck_index) {}
//
//sim_part* blazing_inferno::roll(sim_part* titan_part, double modifier)
//{
//	double chance = card->chance;
//	int counter = titan_part->parent->count_afflicted();
//	if (counter)
//		chance += card->bonus_amount_b[player_card->level] * counter;
//	if (dist(rng) < (chance * modifier))
//		return titan_part;
//	return nullptr;
//}
//
//double blazing_inferno::calculate_dmg(sim_part* titan_part, double modifier)
//{
//	double dmg = card->bonus_amount_a[player_card->level] * modifier;
//	return 0.0;
//}