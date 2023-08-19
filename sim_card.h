#pragma once
#include <vector>
#include <map>
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
	sim_deck* deck;
	int deck_index;
	bool is_burst = false;
	bool is_affliction = false;
	bool is_support = false;
	int stack_counter;
	static sim_card* sim_card_builder(player_card_info* card, int deck_index);
	// might change it to sim_card(player_card_info*)
	sim_card(int index/*, sim_deck* deck*/, int deck_index);
	virtual bool roll(double modifier = 1.);
	virtual void add_stack(sim_part* titan_part, int tap_count);
	virtual void remove_stacks(sim_part* titan_part, int tap_count);
	virtual double calculate_dmg(sim_part* titan_part, double modifier = 1.);
	virtual double calculate_support(double modifier = 1.);
};

class burst : public sim_card
{
public:
	bool is_burst = true;
	using sim_card::sim_card;
};

class affliction : public sim_card
{
public:
	bool is_affliction = true;
	using sim_card::sim_card;
};

class support : public sim_card
{
public:
	bool is_support = true;
	using sim_card::sim_card;
};

/*
class moon_beam : public burst
{
public:
	moon_beam(int deck_index, int index = indexes["moon_beam"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class fragmentize : public burst
{
public:
	fragmentize(int deck_index, int index = indexes["fragmentize"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class skull_bash : public burst
{
public:
	skull_bash(int deck_index, int index = indexes["skull_bash"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class razor_wind : public burst
{
public:
	razor_wind(int deck_index, int index = indexes["razor_wind"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class whip_of_lightning : public burst
{
public:
	whip_of_lightning(int deck_index, int index = indexes["whip_of_lightning"]);
	sim_part* roll(sim_part* titan_part, double modifier);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class clanship_barrage : public burst
{
public:
	clanship_barrage(int deck_index, int index = indexes["clanship_barrage"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class purifying_blast : public burst
{
public:
	// need to implement removing afflictions stacks
	purifying_blast(int deck_index, int index = indexes["purifying_blast"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class psychic_shackles : public burst
{
public:
	psychic_shackles(int deck_index, int index = indexes["psychic_shackles"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class flak_shot : public burst
{
public:
	bool ricochet_flag;
	flak_shot(int deck_index, int index = indexes["flak_shot"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class cosmic_haymaker : public burst
{
public:
	int tap_count;
	cosmic_haymaker(int deck_index, int index = indexes["cosmic_haymaker"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class chain_of_vengeance : public burst
{
public:
	std::vector<sim_part*> previously_hit;
	chain_of_vengeance(int deck_index, int index = indexes["chain_of_vengeance"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class mirror_force : public burst
{
public:
	// might wanna keep it somewhere else
	int clanmates;
	mirror_force(int deck_index, int index = indexes["mirror_force"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class celestial_static : public burst
{
public:
	int charges = 0;
	celestial_static(int deck_index, int index = indexes["celestial_static"]);
	double calculate_dmg(sim_part* titan_part, double modifier);
};

class blazing_inferno : public affliction
{
public:
	blazing_inferno(int deck_index, int index = indexes["blazing_inferno"]);
	sim_part* roll(sim_part* titan_part, double modifier);
	double calculate_dmg(sim_part* titan_part, double modifier);
};
*/