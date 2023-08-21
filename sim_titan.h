#pragma once
#include <string>
#include <vector>
//#include "enumerables.h"
#include "declarations.h"
#include "sim_part.h"

class sim_titan
{
public:
	std::string enemy_id;
	std::string titan_bonus_type;
	double titan_bonus_amount;
	std::string area_bonus_type;
	double area_bonus_amount;
	std::vector<sim_part*> parts;
	std::vector<part_name> attack_order;
	int attack_interval;
	sim_titan(const std::string& enemy_id, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount)
		: enemy_id(enemy_id), titan_bonus_type(titan_bonus_type), titan_bonus_amount(titan_bonus_amount), area_bonus_type(area_bonus_type), area_bonus_amount(area_bonus_amount)
	{}
	void remove_old_stacks(int tap);
	//int count_afflicted();
	//int count_total_bursts();
	//sim_part* random_part(sim_part* skipped_part, bool body_only_flag);
};

class lojak : public sim_titan
{
	lojak(double base_hp, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount);
};