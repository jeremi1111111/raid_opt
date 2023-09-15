#include <iostream>
#include "totem_of_power.h"
#include "../../sim_stack.h"
#include "../../sim_part.h"

// in game, fairies are homing to your tap, so a single point would make a deal
// vectors below store base times between center of a so called hitbox and area edges
// in reality, your taps are always moving
// that's why base delays can be reduced by a random amount, so a tap can trigger fairy in any point of a hitbox
// note that the algorithm doesn't calculate distance, but a time needed to cover this distance (it doesn't even matter where it spawns)
// fairy's effect is activated after you tap it, so there is a delay between spawn and activation
// this delay needs to be calculated to check if given fairy was spawned in correct time
// it's hard to describe how it really works ._.

// everything nice, but it's only needed in the beginning of a simulation
// dude am i wasting time...

const std::vector<std::pair<int, int>> totem_of_power::delay_x_vec = {
    { 35, 35 }, // head
    { 35, 35 }, // torso
    { 11, 58 }, // left arm
    { 11, 58 }, // left hand
    { 58, 11 }, // right arm
    { 58, 11 }, // right hand
    { 24, 45 }, // left leg
    { 45, 24 }  // right leg
};

const std::vector<std::pair<int, int>> totem_of_power::delay_y_vec = {
    { 35, 83 }, // head
    { 54, 64 }, // torso
    { 35, 83 }, // left arm
    { 61, 57 }, // left hand
    { 35, 83 }, // right arm
    { 61, 57 }, // right hand
    { 76, 42 }, // left leg
    { 76, 42 }  // right leg
};

std::uniform_int_distribution<int> totem_of_power::hitbox_delay_roller(0, 6);

const int totem_of_power::delay_threshold = 105;

totem_of_power::totem_of_power(sim_deck* deck, int deck_index)
    : support(card_name::totem_of_power, deck, deck_index)
{
    all_sup_adt = card_data->bonus_amount_a[level];
    stack_duration = card_data->bonus_amount_c * 20;
    spawn_rate = card_data->bonus_amount_d;
    randomness = card_data->bonus_amount_e;
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

    //for (int rp : roll_pattern)
    //    std::cout << rp << ' ';
    //std::cout << '\n' << roll_pattern.size() << '\n';
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
    if (tap > delay_threshold)
        return tap + stack_duration;

    //part_name name = stack->get_part()->get_part_name();
    //part_name name = part_name::head;
    int index = static_cast<int>(part_name::head);

    // there is a delay between spawn and applying stack
    // 3.43 sec to fly from wall to wall in a straight line (roughly 69 taps *nice*)

    int delay_x = 0;
    // it's 'random' which side is picked
    if (tap % 2 == 0)
        delay_x = delay_x_vec[index].first;
    else
        delay_x = delay_x_vec[index].second;
    delay_x -= hitbox_delay_roller(rng);

    std::uniform_int_distribution<int> delay_y_roller(-delay_y_vec[index].first, delay_y_vec[index].second);
    int delay_y = std::abs(delay_y_roller(rng));
    delay_y -= hitbox_delay_roller(rng);

    int delay_sq = std::pow(delay_x, 2) + std::pow(delay_y, 2);
    int final_delay = std::pow(delay_sq, 0.5);
    //std::cout << tap << '\t' << delay_x << '\t' << delay_y << '\t' << final_delay << '\t' << tap - final_delay << '\t' << tap + stack_duration << '\n';
    
    if (tap - final_delay < 0)
        return -1;
    return tap + stack_duration;
}

double totem_of_power::calculate_support(sim_part* part, sim_card* other)
{
    return part->get_stack(this)->size() * all_sup_adt;
}

int totem_of_power::get_max_stacks()
{
    return max_stacks;
}

/* junky stuff
file1
170 970 la
170 1315 lh
540 900 h
540 1240 t
910 970 ra
910 1315 rh
380 1555 ll
700 1555 rl

90 350
2250

3,98 603
7,63 400
566
3,43

5,97 920
9,74 664


180 412
155 283 

file2
30 310		400 680		770 1050
240 520		560 840

file3
2,4	48	19 372
3,8	76	190 372
*/