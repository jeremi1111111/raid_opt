#include "blazing_inferno.h"

bool blazing_inferno::roll(double modifier)
{
    int burning_count = deck->get_titan()->count_parts_with_stacks(this);
    double chance = roll_chance + chance_per_burning_part * burning_count;
    if (dist(rng) >= chance * modifier)
        return false;
    return true;
}
