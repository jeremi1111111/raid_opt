#pragma once
#include <vector>
#include <random>
#include "declarations.h"
#include "card_info.h"
#include "player_card_info.h"
#include "sim_titan.h"
#include "sim_stack.h"

class sim_card
{
//protected:
public:
	card_info* card;
	player_card_info* player_card;
	int deck_index;
	// might change it to sim_card(player_card_info*)
	sim_card(int index, int deck_index);
	virtual sim_part* roll(sim_part* titan_part, double modifier = 1.);
	virtual void add_stack(sim_part* titan_part, int tap_count);
	virtual void remove_stacks(sim_part* titan_part, int tap_count);
	virtual double calculate_dmg(sim_part* titan_part, double modifier = 1.);
	virtual double calculate_support(double modifier = 1.);
};

class moon_beam : public sim_card
{
public:
	moon_beam(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class fragmentize : public sim_card
{
public:
	fragmentize(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class skull_bash : public sim_card
{
public:
	skull_bash(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class razor_wind : public sim_card
{
public:
	razor_wind(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class whip_of_lightning : public sim_card
{
public:
	whip_of_lightning(int deck_index);
	sim_part* roll(sim_part* titan_part, double modifier);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class clanship_barrage : public sim_card
{
public:
	clanship_barrage(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class purifying_blast : public sim_card
{
public:
	// need to implement removing afflictions stacks
	purifying_blast(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class psychic_shackles : public sim_card
{
public:
	psychic_shackles(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class flak_shot : public sim_card
{
public:
	bool ricochet_flag;
	flak_shot(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class cosmic_haymaker : public sim_card
{
public:
	int tap_count;
	cosmic_haymaker(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class chain_of_vengeance : public sim_card
{
public:
	std::vector<sim_part*> previously_hit;
	chain_of_vengeance(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class mirror_force : public sim_card
{
public:
	// might wanna keep it somewhere else, so there is no need for custom constructor
	int clanmates;
	mirror_force(int deck_index, int clanmates);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class celestial_static : public sim_card
{
public:
	int charges = 0;
	celestial_static(int deck_index);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class blazing_inferno : public sim_card
{
public:
	std::vector<sim_part*> previously_hit;
	blazing_inferno(int deck_index);
	sim_part* roll(sim_part* titan_part, double modifier);
	double calculate_dmg(sim_part* titan_part, double modifier);
};