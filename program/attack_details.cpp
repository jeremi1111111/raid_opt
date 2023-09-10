#include "attack_details.h"

attack_details::attack_details(player_info* player, const std::vector<part_name>& order, int interval, int max_taps)
	: order(order), interval(interval), max_taps(max_taps)
{
	base_dmg = player->get_base_dmg();
	counter = 0;
	current = this->order.begin();
}

void attack_details::progress()
{
	current++;
	if (current == order.end())
		current = order.begin();
	counter = 0;
}

part_name attack_details::get_part_name()
{
	return *current;
}

double attack_details::get_base_dmg()
{
	return base_dmg;
}

int attack_details::get_max_taps()
{
	return max_taps;
}
