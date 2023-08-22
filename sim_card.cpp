#include "sim_card.h"

// IMPORTANT!!!
// APPLY DAMAGES TO PARTS
// increase stack counters

std::vector<std::function<sim_card* (sim_deck*, int)>> sim_card::scb =
{
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new moon_beam(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new fragmentize(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new skull_bash(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new razor_wind(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new whip_of_lightning(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new clanship_barrage(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new purifying_blast(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new psychic_shackles(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new flak_shot(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new cosmic_haymaker(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new chain_of_vengeance(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new mirror_force(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new celestial_static(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new blazing_inferno(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new acid_drench(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new decaying_strike(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new fusion_bomb(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new grim_shadow(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new thriving_plague(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new radioactivity(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new ravenous_swarm(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new ruinous_rain(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new corrosive_bubbles(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new maelstrom(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new crushing_instinct(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new insanity_void(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new rancid_gas(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new inspiring_force(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new soul_fire(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new victory_march(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new prismatic_rift(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new ancestral_favor(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new grasping_vines(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new totem_of_power(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new team_tactics(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new skeletal_smash(deck, deck_index); },
	[](sim_deck* deck, int deck_index) -> sim_card*
	{ return new astral_echo(deck, deck_index); }
};

sim_card* sim_card::sim_card_builder(card_name name, sim_deck* deck, int deck_index)
{
	switch (name)
	{
	case card_name::moon_beam:
		return new moon_beam(deck, deck_index);
	case card_name::fragmentize:
		return new fragmentize(deck, deck_index);
	case card_name::skull_bash:
		return new skull_bash(deck, deck_index);
	case card_name::razor_wind:
		return new razor_wind(deck, deck_index);
	case card_name::whip_of_lightning:
		return new whip_of_lightning(deck, deck_index);
	case card_name::clanship_barrage:
		return new clanship_barrage(deck, deck_index);
	case card_name::purifying_blast:
		return new purifying_blast(deck, deck_index);
	case card_name::psychic_shackles:
		return new psychic_shackles(deck, deck_index);
	case card_name::flak_shot:
		return new flak_shot(deck, deck_index);
	case card_name::cosmic_haymaker:
		return new cosmic_haymaker(deck, deck_index);
	case card_name::chain_of_vengeance:
		return new chain_of_vengeance(deck, deck_index);
	case card_name::mirror_force:
		return new mirror_force(deck, deck_index);
	case card_name::celestial_static:
		return new celestial_static(deck, deck_index);
	case card_name::blazing_inferno:
		return new blazing_inferno(deck, deck_index);
	case card_name::acid_drench:
		return new acid_drench(deck, deck_index);
	case card_name::decaying_strike:
		return new decaying_strike(deck, deck_index);
	case card_name::fusion_bomb:
		return new fusion_bomb(deck, deck_index);
	case card_name::grim_shadow:
		return new grim_shadow(deck, deck_index);
	case card_name::thriving_plague:
		return new thriving_plague(deck, deck_index);
	case card_name::radioactivity:
		return new radioactivity(deck, deck_index);
	case card_name::ravenous_swarm:
		return new ravenous_swarm(deck, deck_index);
	case card_name::ruinous_rain:
		return new ruinous_rain(deck, deck_index);
	case card_name::corrosive_bubbles:
		return new corrosive_bubbles(deck, deck_index);
	case card_name::maelstrom:
		return new maelstrom(deck, deck_index);
	case card_name::crushing_instinct:
		return new crushing_instinct(deck, deck_index);
	case card_name::insanity_void:
		return new insanity_void(deck, deck_index);
	case card_name::rancid_gas:
		return new rancid_gas(deck, deck_index);
	case card_name::inspiring_force:
		return new inspiring_force(deck, deck_index);
	case card_name::soul_fire:
		return new soul_fire(deck, deck_index);
	case card_name::victory_march:
		return new victory_march(deck, deck_index);
	case card_name::prismatic_rift:
		return new prismatic_rift(deck, deck_index);
	case card_name::ancestral_favor:
		return new ancestral_favor(deck, deck_index);
	case card_name::grasping_vines:
		return new grasping_vines(deck, deck_index);
	case card_name::totem_of_power:
		return new totem_of_power(deck, deck_index);
	case card_name::team_tactics:
		return new team_tactics(deck, deck_index);
	case card_name::skeletal_smash:
		return new skeletal_smash(deck, deck_index);
	case card_name::astral_echo:
		return new astral_echo(deck, deck_index);
	default:
		return nullptr;
	}
}

sim_card::sim_card(const card_name name, sim_deck* deck, int deck_index)
	: name(name), deck(deck), deck_index(deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	int level = player_cards[index]->level - 1;
	this->roll_chance = ci[index].chance;
	this->base_dmg = ci->bonus_amount_a[level];
}

bool sim_card::roll(sim_part* part, double modifier)
{
	if (dist(rng) < (this->roll_chance * modifier))
	{
		this->counter++;
		return true;
	}
	return false;
}

double sim_card::roll_boost()
{
	return 1.0;
}
/*
void sim_card::add_stack(sim_part* titan_part, int tap_count)
{
	if (!titan_part)
		return;
	std::vector<int>& stack = titan_part->deck_stacks[deck_index];
	stack.push_back(tap_count + card->duration * 20);
	if (stack.size() + 1 > card->max_stacks)
		stack.erase(stack.begin());
}

void sim_card::remove_stacks(sim_part* titan_part, int tap_count)
{
	if (!titan_part)
		return;
	std::vector<int>& stack = titan_part->deck_stacks[deck_index];
	if (stack.empty())
		return;
	auto new_end_iter =  std::remove_if(stack.begin(), stack.end(),
		[tap_count](int end_tap) { return end_tap <= tap_count; });
	stack.erase(new_end_iter, stack.end());
}
*/
double sim_card::calculate_dmg(sim_part* part, double modifier)
{
	return 0.0;
}
/*
double sim_card::calculate_support(double modifier)
{
	return 1.0;
}
*/

moon_beam::moon_beam(sim_deck* deck, int deck_index)
	: sim_card(card_name::moon_beam, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->torso_dmg_mult = ci->bonus_amount_c;
}

double moon_beam::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	if (part->name == part_name::torso)
		dmg *= this->torso_dmg_mult;
	return dmg;
}

fragmentize::fragmentize(sim_deck* deck, int deck_index)
	: sim_card(card_name::fragmentize, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	int level = player_cards[index]->level - 1;
	this->category = card_category::burst;
	this->cursed_dmg_mult = ci->bonus_amount_b[level];
	this->armor_dmg_mult = ci->bonus_amount_c;
}

double fragmentize::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	if (part->ap > 0.)
	{
		dmg *= this->armor_dmg_mult;
		if (part->is_cursed)
			dmg *= this->cursed_dmg_mult;
	}
	return dmg;
}

skull_bash::skull_bash(sim_deck* deck, int deck_index)
	: sim_card(card_name::skull_bash, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->head_dmg_mult = ci->bonus_amount_c;
}


double skull_bash::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = base_dmg * modifier;
	if (part->name == part_name::head)
		dmg *= head_dmg_mult;
	return dmg;
}

razor_wind::razor_wind(sim_deck* deck, int deck_index)
	: sim_card(card_name::razor_wind, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->body_dmg_mult = ci->bonus_amount_c;
}

double razor_wind::calculate_dmg(sim_part* titan_part, double modifier)
{
	double dmg = base_dmg * modifier;
	if (titan_part->ap == 0.)
		dmg *= body_dmg_mult;
	return dmg;
}

whip_of_lightning::whip_of_lightning(sim_deck* deck, int deck_index)
	: sim_card(card_name::whip_of_lightning, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	int level = player_cards[index]->level - 1;
	this->category = card_category::burst;
	this->chance_per_afflicted_part = ci->bonus_amount_b[level];
	this->max_bonus_chance = ci->bonus_amount_c;
}

bool whip_of_lightning::roll(sim_part* part, double modifier)
{
	double chance = this->roll_chance;
	int affliction_counter = part->titan->count_afflicted();
	if (affliction_counter)
		chance += std::min(this->chance_per_afflicted_part * affliction_counter, this->max_bonus_chance);
	if (dist(rng) < (chance * modifier))
		return true;
	return false;
}

double whip_of_lightning::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	return dmg;
}

clanship_barrage::clanship_barrage(sim_deck* deck, int deck_index)
	: sim_card(card_name::clanship_barrage, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->dmg_adt_per_burst = ci->bonus_amount_c;
}

double clanship_barrage::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	int burst_counter = this->deck->total_burst_count();
	if (burst_counter)
		dmg *= 1. + this->dmg_adt_per_burst * burst_counter;
	return dmg;
}

purifying_blast::purifying_blast(sim_deck* deck, int deck_index)
	: sim_card(card_name::purifying_blast, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->dmg_adt_per_affliction = ci->bonus_amount_c;
}

double purifying_blast::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = base_dmg * modifier;
	int affliction_counter = part->count_afflicted_stacks();
	if (affliction_counter)
		dmg *= 1. + dmg_adt_per_affliction * affliction_counter;
	part->invalidate_afflictions();
	return dmg;
}

psychic_shackles::psychic_shackles(sim_deck* deck, int deck_index)
	: sim_card(card_name::psychic_shackles, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->limb_dmg_mult = ci->bonus_amount_c;
}

double psychic_shackles::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	if (part->name != part_name::head &&
		part->name != part_name::torso)
		dmg *= this->limb_dmg_mult;
	return dmg;
}

flak_shot::flak_shot(sim_deck* deck, int deck_index)
	: sim_card(card_name::flak_shot, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->richochet_dmg_mult = ci->bonus_amount_c;
	this->ricochet_flag = false;
}

double flak_shot::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	if (ricochet_flag && part->ap == 0.)
	{
		dmg *= this->richochet_dmg_mult;
		ricochet_flag = false;
	}
	return dmg;
}

bool flak_shot::roll(sim_part* part, double modifier)
{
	ricochet_flag = false;
	if (sim_card::roll(part, modifier))
	{
		if (part->ap > 0.)
			ricochet_flag = true;
		return true;
	}
	return false;
	//there needs to be a call for random ricochet part, maybe it should be in add_stack?
}

cosmic_haymaker::cosmic_haymaker(sim_deck* deck, int deck_index)
	: sim_card(card_name::cosmic_haymaker, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->tap_count_for_outburst = ci->bonus_amount_c;
}

bool cosmic_haymaker::roll(sim_part* part, double modifier)
{
	this->tap_count++;
	if (this->tap_count == this->tap_count_for_outburst)
		return true;
	return false;
}

double cosmic_haymaker::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	return dmg;
}
chain_of_vengeance::chain_of_vengeance(sim_deck* deck, int deck_index)
	: sim_card(card_name::chain_of_vengeance, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->max_targets = ci->bonus_amount_d;
}

bool chain_of_vengeance::roll(sim_part* part, double modifier)
{
	if (sim_card::roll(part, modifier))
	{
		if (this->previously_hit.size() < this->max_targets
				&& std::find(this->previously_hit.begin(), this->previously_hit.end(), part->name) == this->previously_hit.end())
			previously_hit.push_back(part->name);
		return true;
	}
	return false;
}

double chain_of_vengeance::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier / this->previously_hit.size();
	return dmg;
}

mirror_force::mirror_force(sim_deck* deck, int deck_index)
	: sim_card(card_name::mirror_force, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->dmg_mult_per_clanmate = ci->bonus_amount_c;
	this->max_boost = ci->bonus_amount_d;
}

double mirror_force::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = base_dmg * modifier;
	if (clanmates)
		dmg *= 1. + std::min(clanmates * this->dmg_mult_per_clanmate, this->max_boost);
	return dmg;
}

celestial_static::celestial_static(sim_deck* deck, int deck_index)
	: sim_card(card_name::celestial_static, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->charges_per_burst = ci->bonus_amount_c;
	this->charges_per_tap = ci->bonus_amount_d;
	this->max_charges = ci->bonus_amount_e;
}

bool celestial_static::roll(sim_part* part, double modifier)
{
	if (part->ap != 0. && this->charges - this->charges_per_burst >= 0)
	{
		this->charges -= this->charges_per_burst;
		return true;
	}
	if (part->ap == 0.)
		this->charges = std::min(this->charges + this->charges_per_tap, this->max_charges);
	return false;
}

double celestial_static::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = base_dmg * modifier;
	return dmg;
}

blazing_inferno::blazing_inferno(sim_deck* deck, int deck_index)
	: sim_card(card_name::blazing_inferno, deck, deck_index)
{
	int index = static_cast<int>(name);
	card_info* ci = cards[index];
	this->category = card_category::burst;
	this->chance_per_burning_part = ci->bonus_amount_c;
}

bool blazing_inferno::roll(sim_part* part, double modifier)
{
	double chance = roll_chance;
	int burning_counter = part->titan->count_parts_with_stacks(this);
	if (burning_counter)
		chance += chance_per_burning_part * burning_counter;
	if (dist(rng) < (chance * modifier))
		return true;
	return false;
}

double blazing_inferno::calculate_dmg(sim_part* part, double modifier)
{
	double dmg = this->base_dmg * modifier;
	return dmg;
	// dmg per one stack, it's so generic i think about putting it into virtual function in sim_card
}