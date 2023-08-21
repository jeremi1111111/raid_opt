#pragma once
//#include <vector>
//#include <random>
//#include "enumerables.h"
#include "declarations.h"
//#include "sim_deck.h"
//#include "sim_titan.h"
#include "card_info.h"
#include "player_card_info.h"

class sim_card
{
//protected:
public:
	card_name name;
	sim_deck* deck;
	int deck_index;
	card_category category;
	double roll_chance;
	double base_dmg;
	static sim_card* sim_card_builder(card_name name, sim_deck* deck, int deck_index);
	sim_card(const card_name name, sim_deck* deck, int deck_index);
	virtual bool roll(double modifier = 1.);
	//virtual void add_stack(sim_part* titan_part, int tap_count);
	//virtual void remove_stacks(sim_part* titan_part, int tap_count);
	virtual double calculate_dmg(double modifier = 1.);
	//virtual double calculate_support(double modifier = 1.);
	virtual double roll_boost();
};

class moon_beam : public sim_card
{
public:
	double torso_dmg_mult;
	moon_beam(sim_deck* deck, int deck_index);
	double calculate_dmg(double modifier);
};

class fragmentize : public sim_card
{
public:
	double cursed_dmg_mult;
	double armor_dmg_mult;
	fragmentize(sim_deck* deck, int deck_index);
};

class skull_bash : public sim_card
{
public:
	double head_dmg_mult;
	skull_bash(sim_deck* deck, int deck_index);
};

class razor_wind : public sim_card
{
public:
	double body_dmg_mult;
	razor_wind(sim_deck* deck, int deck_index);
};

class whip_of_lightning : public sim_card
{
public:
	double chance_per_afflicted_part;
	double max_bonus_chance;
	whip_of_lightning(sim_deck* deck, int deck_index);
	bool roll(double modifier);
};

class clanship_barrage : public sim_card
{
public:
	double dmg_adt_per_burst;
	clanship_barrage(sim_deck* deck, int deck_index);
};

class purifying_blast : public sim_card
{
public:
	double dmg_adt_per_affliction;
	// need to implement removing afflictions stacks
	purifying_blast(sim_deck* deck, int deck_index);
};

class psychic_shackles : public sim_card
{
public:
	double limb_dmg_mult;
	psychic_shackles(sim_deck* deck, int deck_index);
};

class flak_shot : public sim_card
{
public:
	double richochet_dmg_mult;
	bool ricochet_flag;
	flak_shot(sim_deck* deck, int deck_index);
};

class cosmic_haymaker : public sim_card
{
public:
	int tap_count_for_outburst;
	int tap_count;
	cosmic_haymaker(sim_deck* deck, int deck_index);
};

class chain_of_vengeance : public sim_card
{
public:
	std::vector<part_name> previously_hit;
	chain_of_vengeance(sim_deck* deck, int deck_index);
};

class mirror_force : public sim_card
{
public:
	double dmg_mult_per_clanmate;
	int max_clanmates;
	// might wanna keep it somewhere else
	int clanmates;
	mirror_force(sim_deck* deck, int deck_index);
};

class celestial_static : public sim_card
{
public:
	int charges_per_burst;
	int charges_per_tap;
	int max_charges;
	int charges = 0;
	celestial_static(sim_deck* deck, int deck_index);
};

class blazing_inferno : public sim_card
{
public:
	double chance_per_burning_part;
	blazing_inferno(sim_deck* deck, int deck_index);
	bool roll(double modifier = 1.);
};

class acid_drench : public sim_card
{
public:
	acid_drench(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};

class decaying_strike : public sim_card
{
public:
	double max_dmg_exponent;
	double max_missing_hp;
	decaying_strike(sim_deck* deck, int deck_index);
};

class fusion_bomb : public sim_card
{
public:
	double refresh_chance;
	fusion_bomb(sim_deck* deck, int deck_index);
};
class grim_shadow : public sim_card 
{
public:
	double dmg_mult_per_stack;
	grim_shadow(sim_deck* deck, int deck_index);
};
class thriving_plague : public sim_card
{
public:
	double dmg_mult_per_afflicted_part;
	thriving_plague(sim_deck* deck, int deck_index);
};
class radioactivity : public sim_card
{
public:
	double dmg_mult_per_second;
	radioactivity(sim_deck* deck, int deck_index);
};
class ravenous_swarm : public sim_card
{
public:
	ravenous_swarm(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};
class ruinous_rain : public sim_card
{
public:
	double cursed_dmg_mult;
	ruinous_rain(sim_deck* deck, int deck_index);
};
class corrosive_bubbles : public sim_card
{
public:
	double outburst_dmg_mult;
	corrosive_bubbles(sim_deck* deck, int deck_index);
};
class maelstrom : public sim_card
{
public:
	double sup_adt_per_stack;
	maelstrom(sim_deck* deck, int deck_index);
};
class crushing_instinct : public sim_card
{
public:
	double head_sup_adt;
	double torso_sup_adt;
	double burst_chance_mult;
	crushing_instinct(sim_deck* deck, int deck_index);
};
class insanity_void : public sim_card
{
public:
	double all_sup_adt;
	double all_sup_adt_per_body_part;
	insanity_void(sim_deck* deck, int deck_index);
};
class rancid_gas : public sim_card
{
public:
	double affliction_sup_adt;
	double affliction_chance_mult;
	rancid_gas(sim_deck* deck, int deck_index);
};
class inspiring_force : public sim_card
{
public:
	double body_sup_adt;
	inspiring_force(sim_deck* deck, int deck_index);
};
class soul_fire : public sim_card
{
public:
	double head_sup_adt;
	double torso_sup_adt;
	double affliction_chance_mult;
	soul_fire(sim_deck* deck, int deck_index);
};
class victory_march : public sim_card
{
public:
	double all_sup_adt;
	double all_sup_adt_per_dead_part;
	victory_march(sim_deck* deck, int deck_index);
};
class prismatic_rift : public sim_card
{
public:
	double armor_sup_adt;
	prismatic_rift(sim_deck* deck, int deck_index);
};
class ancestral_favor : public sim_card
{
public:
	double burst_sup_adt;
	double burst_chance_mult;
	ancestral_favor(sim_deck* deck, int deck_index);
};
class grasping_vines : public sim_card
{
public:
	double limb_sup_adt;
	grasping_vines(sim_deck* deck, int deck_index);
};
class totem_of_power : public sim_card
{
public:
	double stack_duration;
	double spawn_rate;
	double randomness;
	totem_of_power(sim_deck* deck, int deck_index);
	//void add_stack(sim_part* titan_part, int tap_count);
};
class team_tactics : public sim_card
{
public:
	double all_sup_adt;
	team_tactics(sim_deck* deck, int deck_index);
};
class skeletal_smash : public sim_card
{
public:
	double armor_sup_adt;
	double armor_sup_adt_if_dead_parts;
	skeletal_smash(sim_deck* deck, int deck_index);
};
class astral_echo : public sim_card
{
public:
	double all_sup_adt;
	int max_charges;
	double all_chance_mult;
	int charges;
	astral_echo(sim_deck* deck, int deck_index);
};