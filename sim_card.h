#pragma once
#include <vector>
#include <random>
#include "declarations.h"
#include "card_info.h"
#include "player_card_info.h"
#include "sim_titan.h"

class sim_card
{
//protected:
public:
	card_info* card;
	player_card_info* player_card;
	std::vector<int> active_stacks;
	int total_stack_counter = 0;
	// might change it to sim_card(player_card_info*)
	sim_card(int index);
	virtual bool roll(sim_part* titan_part, double modifier = 1.);
	virtual double calculate_dmg(sim_part* titan_part, double modifier = 1.);
	virtual double calculate_support(double modifier = 1.);
};

class moon_beam : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class fragmentize : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class skull_bash : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class razor_wind : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class whip_of_lightning : public sim_card
{
public:
	using sim_card::sim_card;
	bool roll(sim_part* titan_part, double modifier);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class clanship_barrage : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class purifying_blast : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class psychic_shackles : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class flak_shot : public sim_card
{
public:
	bool ricochet_flag = false;
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class cosmic_haymaker : public sim_card
{
public:
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class chain_of_vengeance : public sim_card
{
public:
	std::vector<sim_part*> previously_hit;
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class mirror_force : public sim_card
{
public:
	// might wanna keep it somewhere else, so there is no need for custom constructor
	int clanmates;
	mirror_force(int index, int clanmates);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class celestial_static : public sim_card
{
public:
	int charges = 0;
	using sim_card::sim_card;
	double calculate_dmg(sim_part* titan_part, double modifier);
};
