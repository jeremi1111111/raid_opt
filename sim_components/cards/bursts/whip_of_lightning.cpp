#include "whip_of_lightning.h"

bool whip_of_lightning::roll(double modifier)
{
    int affliction_count = deck->get_titan()->count_afflicted();
    double chance = roll_chance + std::min(chance_per_afflicted_part * affliction_count, max_bonus_chance);
    if (dist(rng) >= chance * modifier)
        return false;
    return true;
}
