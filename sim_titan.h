#pragma once
#include <vector>
#include "declarations.h"
#include "sim_part.h"

class sim_titan
{
public:
	std::vector<sim_part*> parts;
	sim_titan();
	int count_afflicted();
	int count_total_bursts();
	sim_part* random_part(sim_part* skipped_part, bool body_only_flag);
};
