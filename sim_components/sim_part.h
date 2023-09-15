#pragma once
#include <vector>
#include "../game_info/enumerables.h"

class sim_titan;
class sim_stack;
class sim_card;

class sim_part
{
	part_name name;
	sim_titan* titan;
	double hp;
	double ap;
	bool is_cursed;
	//int tap_count;
	std::vector<sim_stack*> deck_stacks;
	//static const std::vector<int> pos_y;
public:
	sim_part(sim_titan* titan, part_name name, double hp, double ap);
	bool is_afflicted();
	int get_affliction_stack_count();
	sim_stack* get_stack(sim_card* card);
	void add_stack(sim_card* card, int tap);
	part_name get_part_name();
	void invalidate_afflictions();
	void create_stacks(std::vector<sim_card*> sim_cards);
	std::vector<sim_stack*> get_deck_stacks();
	// might wanna use it, but i can get around it
	//int get_pos_y();
	/*
	void remove_old_stacks(int tap);
	void remove_first(sim_card* card);
	int count_afflicted_stacks();

	double get_ap();
	*/
};