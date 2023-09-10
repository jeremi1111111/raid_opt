#include <iostream>
#include "totem_of_power.h"
#include "../../sim_stack.h"
#include "../../sim_part.h"

// in game, fairies are homing to your tap, so a single point would make a deal
// in reality, your taps are always moving
// that's why here fairies fly to 4 points, being corners of so called hitbox
// if you think about it a bit longer, you can come to a conclusion that these points aren't really points
// (also, maps below aren't coordinates, they contain time needed to fly to edge from a hitbox boundary)
// it's hard to describe how it really works ._.

const std::unordered_map<part_name, std::pair<int, int>> totem_of_power::base_delay_map = {
    { part_name::head, { 25, 25 }},
    { part_name::torso, { 25, 25 }},
    { part_name::left_arm, { 4, 53 }},
    { part_name::left_hand, { 4, 53 }},
    { part_name::right_arm, { 53, 4 }},
    { part_name::right_hand, { 53, 4 }},
    { part_name::left_leg, { 20, 36 }},
    { part_name::right_leg, { 36, 20 }}
};

const std::unordered_map<part_name, std::pair<int, int>> totem_of_power::extra_delay_map = {
    { part_name::head, { -25, 76 }},
    { part_name::torso, { -50, 57 }},
    { part_name::left_arm, { -31, 73 }},
    { part_name::left_hand, { -57, 50 }},
    { part_name::right_arm, { -31, 73 }},
    { part_name::right_hand, { -57, 50 }},
    { part_name::left_leg, { -67, 34 }},
    { part_name::right_leg, { -67, 34 }}
};

totem_of_power::totem_of_power(sim_deck* deck, int deck_index)
    : support(card_name::totem_of_power, deck, deck_index)
{
    card_info* ci = cards[static_cast<int>(name)];
    stack_duration = ci->bonus_amount_c;
    spawn_rate = ci->bonus_amount_d;
    randomness = ci->bonus_amount_e;

    //int max_taps = deck->get_attack()->get_max_taps();
    int max_taps = 600;
    double step = spawn_rate * 20;

    std::uniform_int_distribution<int> roller(-step, step);

    double current_step = step;
    while (current_step < max_taps)
    {
        roll_pattern.push_back(current_step + roller(rng));
        current_step += step;
    }
    std::sort(roll_pattern.begin(), roll_pattern.end(),
        [](int a, int b) { return a < b; });
    current = roll_pattern.begin();

    for (int rp : roll_pattern)
        std::cout << rp << ' ';
    std::cout << '\n' << roll_pattern.size() << '\n';
}

bool totem_of_power::roll(double modifier)
{
    return true;
}

int totem_of_power::calculate_expire_tap(sim_stack* stack, int tap)
{
    if (current == roll_pattern.end() || tap < *current)
        return -1;
    current++;

    //part_name name = stack->get_part()->get_part_name();
    part_name name = part_name::head;

    // there is a delay between spawn and applying stack
    // 3.43 sec to fly from wall to wall in a straight line

    int base_delay = 0;
    if (tap % 2 == 0)
        base_delay = base_delay_map.at(name).first;
    else
        base_delay = base_delay_map.at(name).second;

    std::uniform_int_distribution<int> extra_dealy_roller(extra_delay_map.at(name).first, extra_delay_map.at(name).second);
    int extra_delay = extra_dealy_roller(rng);

    int delay_sq = std::pow(base_delay, 2) + std::pow(extra_delay, 2);
    int final_delay = std::pow(delay_sq, 0.5);
    std::cout << tap - final_delay << ' ';
    
    if (tap - final_delay < 0)
        return -1;
    return tap + stack_duration;
}