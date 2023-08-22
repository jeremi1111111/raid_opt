#include "sim_titan.h"

void sim_titan::remove_old_stacks(int tap)
{
	for (sim_part* part : parts)
		part->remove_old_stacks(tap);
}

int sim_titan::count_afflicted()
{
	int counter = 0;
	for (sim_part* part : parts)
		counter += part->is_afflicted();
    return counter;
}

int sim_titan::count_parts_with_stacks(sim_card* card)
{
	int counter = 0;
	for (sim_part* part : this->parts)
		if (!part->deck_stacks[card->deck_index]->active_stacks.empty())
			counter++;
	return counter;
}

sim_part* sim_titan::random_part(sim_part* skipped_part, bool body_only_flag)
{
	std::vector<sim_part*> rollable_parts;
	for (sim_part* part : parts)
	{
		if (part == skipped_part || (body_only_flag && part->ap > 0.))
			continue;
		rollable_parts.push_back(part);
	}
	std::uniform_int_distribution<int> dint(0, rollable_parts.size());
	return rollable_parts[dint(rng)];
}

double sim_titan::apply_dmg(part_name name, double base_dmg)
{

}

lojak::lojak(double base_hp, const std::string& titan_bonus_type, double titan_bonus_amount, const std::string& area_bonus_type, double area_bonus_amount)
	: sim_titan(enemy_id::lojak, titan_bonus_type, titan_bonus_amount, area_bonus_type, area_bonus_amount)
{
	this->parts.push_back(new sim_part(this, part_name::head));
}