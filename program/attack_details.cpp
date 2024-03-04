#include "attack_details.h"

attack_details::attack_details(player_info* player, const std::vector<part_name>& order_template, int interval, int max_taps)
	: order(order_template), max_taps(max_taps)
{
	auto it = order_template.begin();
	while (order.size() < max_taps)
	{
		order.insert(order.end(), interval, *it);
		it++;
		if (it == order_template.end())
			it = order_template.begin();
	}
	//for (part_name name : order_template)
	//	order.insert(order.end(), interval, name);
	base_dmg = player->get_base_dmg();
}

part_name attack_details::get_part_name(int tap)
{
	return order[tap];
}

double attack_details::get_base_dmg()
{
	return base_dmg;
}

int attack_details::get_max_taps()
{
	return max_taps;
}
