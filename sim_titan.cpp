#include "sim_titan.h"

sim_titan::sim_titan()
{
	for (int i = 0; i < 8; i++)
		parts.push_back(new sim_part(this, static_cast<part_name>(i)));
}

int sim_titan::count_afflicted()
{
	int counter = 0;
	for (sim_part* part : parts)
		counter += part->is_afflicted();
    return counter;
}

int sim_titan::count_total_bursts()
{
	int counter = 0;
	for (sim_part* part : parts)
		counter += part->count_bursts();
	return counter;
}

int sim_titan::count_all_taps()
{
	int counter = 0;
	for (sim_part* part : parts)
		counter += part->tap_count;
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
