#include "fusion_bomb.h"

bool fusion_bomb::roll(double modifier)
{
    if (deck->get_titan()->stack_count(deck->get_attack()->get_part_name(), this))
        if (dist(rng) >= refresh_chance * modifier)
            return false;
        else
            return true;
    return sim_card::roll(modifier);
}
