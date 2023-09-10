#pragma once
#include <string>
#include <vector>
#include "../game_info/enumerables.h"

class sim_card;
class sim_part;

class sim_titan
{
	enemy_id name;
	std::string titan_bonus_type;
	double titan_bonus_amount;
	std::string area_bonus_type;
	double area_bonus_amount;
	std::vector<sim_part*> parts;
public:
	sim_titan(const enemy_id& name, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount)
		: name(name), titan_bonus_type(titan_bonus_type), titan_bonus_amount(titan_bonus_amount), area_bonus_type(area_bonus_type), area_bonus_amount(area_bonus_amount)
	{}
	sim_part* get_part(part_name name);
	int stack_count(part_name name, sim_card* card);
	int count_parts_with_stacks(sim_card* card);
	int count_afflicted();
	/*
	void remove_old_stacks(int tap);
	//int count_total_bursts();
	sim_part* random_part(sim_part* skipped_part, bool body_only_flag);
	double apply_dmg(double base_dmg);
	*/
};

//class lojak : public sim_titan
//{
//public:
//	lojak(double base_hp, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount);
//};