#include <iostream>
#include "sim_titan.h"
#include "sim_part.h"
#include "sim_stack.h"
#include "../program/simulation.h"
#include "../game_info/titan_info.h"

sim_titan::sim_titan(enemy_id name, double base_hp)
	: name(name)
{
	titan_info* ti = titans[static_cast<int>(name)];
	parts = {
		new sim_part(this, part_name::head, base_hp * ti->body_head_mult, base_hp * ti->armor_head_mult),
		new sim_part(this, part_name::torso, base_hp * ti->body_torso_mult, base_hp * ti->armor_torso_mult),
		new sim_part(this, part_name::left_arm, base_hp * ti->body_arms_mult / 4, base_hp * ti->armor_arms_mult / 4),
		new sim_part(this, part_name::left_hand, base_hp * ti->body_arms_mult / 4, base_hp * ti->armor_arms_mult / 4),
		new sim_part(this, part_name::right_arm, base_hp * ti->body_arms_mult / 4, base_hp * ti->armor_arms_mult / 4),
		new sim_part(this, part_name::right_hand, base_hp * ti->body_arms_mult / 4, base_hp * ti->armor_arms_mult / 4),
		new sim_part(this, part_name::left_leg, base_hp * ti->body_legs_mult / 2, base_hp * ti->armor_legs_mult / 2),
		new sim_part(this, part_name::right_leg, base_hp * ti->body_legs_mult / 2, base_hp * ti->armor_legs_mult / 2),
	};
}

sim_part* sim_titan::get_part(part_name name)
{
	return parts[static_cast<int>(name)];
}

//void sim_titan::remove_old_stacks(int tap)
//{
//	for (sim_part* part : parts)
//		part->remove_old_stacks(tap);
//}

int sim_titan::count_afflicted()
{
	int counter = 0;
	for (sim_part* part : parts)
		counter += part->is_afflicted();
    return counter;
}

void sim_titan::set_cards(std::vector<sim_card*> sim_cards)
{
	for (sim_part* part : parts)
		part->create_stacks(sim_cards);
}

std::vector<sim_part*> sim_titan::get_parts()
{
	return parts;
}

int sim_titan::count_parts_with_stacks(sim_card* card)
{
	int counter = 0;
	for (sim_part* part : parts)
		if (!part->get_stack(card)->empty())
			counter++;
	return counter;
}

//sim_part* sim_titan::random_part(sim_part* skipped_part, bool body_only_flag)
//{
//	std::vector<sim_part*> rollable_parts;
//	for (sim_part* part : parts)
//	{
//		if (part == skipped_part || (body_only_flag && part->get_ap() > 0.))
//			continue;
//		rollable_parts.push_back(part);
//	}
//	std::uniform_int_distribution<int> dint(0, rollable_parts.size());
//	return rollable_parts[dint(rng)];
//}

//lojak::lojak(double base_hp, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount)
//	: sim_titan(enemy_id::lojak, titan_bonus_type, titan_bonus_amount, area_bonus_type, area_bonus_amount)
//{
//	this->parts.push_back(new sim_part(this, part_name::head));
//}